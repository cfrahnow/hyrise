// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include <access/SortScan.h>

#include <algorithm>

#include "access/QueryParser.h"

#include "helper/types.h"

#include "storage/storage_types.h"
#include "storage/AbstractTable.h"
#include "storage/PointerCalculator.h"
#include "storage/PointerCalculatorFactory.h"
#include "storage/Table.h"

bool SortScan::is_registered = QueryParser::registerPlanOperation<SortScan>();

template <typename T>
struct ExtractValue {
  static inline T extractValue(const hyrise::storage::c_atable_ptr_t& table,
                               const size_t& col,
                               const size_t& row) {
    return table->getValue<T>(col, row);
  }
};

template <typename T>
struct ExtractValueId {
  static inline ValueId extractValue(const hyrise::storage::c_atable_ptr_t& table,
                                        const size_t& col,
                                        const size_t& row) {
    return table->getValueId(col, row);
  }
};


template <typename T, template<typename T> class ExtractFunctor>
class ColumnSorter {
  typedef struct pair {
      T value;
      size_t row;
  } pair_t;

  const hyrise::storage::c_atable_ptr_t& _t;
  field_t _f;

 public:
  ColumnSorter(const hyrise::storage::c_atable_ptr_t& t, field_t f): _t(t), _f(f) {
  }

  std::vector<pos_t>* sort() const {
    std::vector<pair_t> result;

    for (size_t row = 0; row < _t->size(); ++row) {
      result.push_back({ExtractFunctor<T>::extractValue(_t, _f, row), row});
    }

    std::stable_sort(result.begin(),
                     result.end(),
                     [](const pair_t& left, const pair_t& right)
                     { return left.value < right.value; });

    auto r = new std::vector<pos_t>;
    r->reserve(result.size());
    for (const pair_t& p: result)
      r->push_back(p.row);

    return r;
  }
};

std::shared_ptr<_PlanOperation> SortScan::parse(Json::Value &data) {
  std::shared_ptr<SortScan> s = std::make_shared<SortScan>();
  s->setSortField(data["fields"][0u].asUInt());
  return s;
}


void SortScan::executePlanOperation() {
  const auto& table = input.getTable(0);
  // Sorted Position List
  std::vector<pos_t> *sorted_pos;

  // When table is not only a table but also using an ordered dictionary on sort field,
  // we can just sort by value_id
  // TODO: fix Table<> template
  auto base_table = std::dynamic_pointer_cast<const Table<>>(table);
  if ((table->dictionaryAt(_sort_field)->isOrdered()) && (base_table)) {
    sorted_pos = ColumnSorter<ValueId, ExtractValueId>(table, _sort_field).sort();
  } else {
    switch (table->metadataAt(_sort_field)->getType()) {
      case IntegerType:
        sorted_pos = ColumnSorter<hyrise_int_t, ExtractValue>(table, _sort_field).sort();
        break;
      case FloatType:
        sorted_pos = ColumnSorter<hyrise_float_t, ExtractValue>(table, _sort_field).sort();
        break;
      case StringType:
        sorted_pos = ColumnSorter<hyrise_string_t, ExtractValue>(table, _sort_field).sort();
        break;
      default:
        throw std::runtime_error("Datatype not supported");
    }
  }

  hyrise::storage::atable_ptr_t result;
  if (producesPositions) {
    result = PointerCalculatorFactory::createPointerCalculatorNonRef(table, nullptr, sorted_pos);
  } else {
    result = table->copy_structure_modifiable(nullptr, true);
    size_t result_row = 0;
    for (const auto& p: *sorted_pos) {
      result->copyRowFrom(table, p, result_row++);
    }
    delete sorted_pos;
  }
  addResult(result);
}


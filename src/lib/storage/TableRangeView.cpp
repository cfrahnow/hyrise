// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
/*
 * TableRangeView.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: jwust
 */

#include "TableRangeView.h"
#include "storage/PrettyPrinter.h"


TableRangeView::TableRangeView(hyrise::storage::atable_ptr_t t, size_t s, size_t e): _table(t), _start(s), _end(e) {
  _columnCount = _table->columnCount();
}

TableRangeView::~TableRangeView() {
  // TODO Auto-generated destructor stub
}

size_t TableRangeView::getStart() const{
  return _start;
}

size_t TableRangeView::size() const {
  return _end-_start+1;
}

void TableRangeView::setValueId(const size_t column, const size_t row, const ValueId valueId){
  size_t actual_row;
  actual_row = row + _start;

  return _table->setValueId(column, actual_row, valueId);
}

ValueId TableRangeView::getValueId(const size_t column, const size_t row) const{
  size_t actual_row;
  actual_row = row + _start;

  return _table->getValueId(column, actual_row);
}

void *TableRangeView::atSlice(const size_t slice, const size_t row) const{
  size_t actual_row;
  actual_row = row + _start;
  return _table->atSlice(slice, actual_row);
}

size_t TableRangeView::getSliceWidth(const size_t slice) const{
  return _table->getSliceWidth(slice);
}

size_t TableRangeView::getSliceForColumn(const size_t column) const{
  return _table->getSliceForColumn(column);
}

size_t TableRangeView::getOffsetInSlice(const size_t column) const{
  return _table->getOffsetInSlice(column);
}

void TableRangeView::print(std::ostream& outStream, const std::string tableName, const size_t limit) const{
  size_t actual_limit = limit;
  if(limit > size())
    actual_limit = size();
  PrettyPrinter::print(this, tableName, outStream, actual_limit, _start);
}

void TableRangeView::sortDictionary(){
  throw std::runtime_error("Can't sort TableRangeView dictionary");
};

table_id_t TableRangeView::subtableCount() const{
  return 1;
}

hyrise::storage::atable_ptr_t TableRangeView::copy() const{
  return std::make_shared<TableRangeView>(_table, _start, _end);
}

hyrise::storage::atable_ptr_t TableRangeView::copy_structure(const field_list_t *fields, const bool reuse_dict, const size_t initial_size, const bool with_containers, const bool compressed) const{
  return _table->copy_structure(fields, reuse_dict, initial_size, with_containers, compressed);
}

const ColumnMetadata *TableRangeView::metadataAt(const size_t column, const size_t row, const table_id_t table_id) const{
  size_t actual_row;
  actual_row = row + _start;

  return _table->metadataAt(column, actual_row, table_id);
};

const AbstractTable::SharedDictionaryPtr & TableRangeView::dictionaryAt(const size_t column, const size_t row, const table_id_t table_id , const bool of_delta) const{
  size_t actual_row;
  actual_row = row + _start;

  return _table->dictionaryAt(column, actual_row, table_id, of_delta);
}

const AbstractTable::SharedDictionaryPtr & TableRangeView::dictionaryByTableId(const size_t column, const table_id_t table_id) const{
  return _table->dictionaryByTableId(column, table_id);
}

void TableRangeView::setDictionaryAt(SharedDictionaryPtr dict, const size_t column, const size_t row, const table_id_t table_id){
  throw std::runtime_error("Can't set dictionary of TableRangeView");
}

DataType TableRangeView::typeOfColumn(const size_t column) const{
  return _table->typeOfColumn(column);
}

size_t TableRangeView::columnCount() const{
  return _columnCount;
}

std::string TableRangeView::nameOfColumn(const size_t column) const {
  return _table->nameOfColumn(column);
}

unsigned TableRangeView::sliceCount() const{
  return _table->sliceCount();
}

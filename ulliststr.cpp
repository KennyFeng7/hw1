#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
  
  if (tail_ == NULL){
    Item *newItem = new Item();
    tail_ = newItem;
    head_ = newItem;
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
  else if(tail_->last == ARRSIZE){
    Item *newItem = new Item();
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
}

void ULListStr::pop_back() {
  if (empty()) {
    throw std::out_of_range("Empty List");
  }
  tail_->last--;
  if (tail_->last == tail_->first) {
    Item *holder = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL) {
      tail_->next = NULL;
    } 
    else {
      head_ = NULL;
    }
    delete holder;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
  
  if (head_ == NULL){
    Item *newItem = new Item();
    head_ = newItem;
    tail_ = newItem;
    head_->val[head_->first] = val;
    head_->last++;
    size_++;
  }
  else if(head_->first == 0){
    Item *newItem = new Item();
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE - 1;
    head_->prev = newItem;
    newItem->next = head_;
    head_ = newItem;
    head_->val[head_->first] = val;
    size_++;
  }
  else{
    (head_->first)--;
    head_->val[head_->first] = val;
    size_++;
  }
}

void ULListStr::pop_front() {
  if (empty()) {
    throw std::out_of_range("Empty List");
  }
  (head_->first)++;
  if (head_->first == head_->last) {
    Item *holder = head_;
    head_ = head_->next;
    if (head_ != NULL) {
      head_->prev = NULL;
    } 
    else {
      tail_ = NULL;
    }
    delete holder;
  }
  size_--;
}

std::string const& ULListStr::back() const {
  if (empty()) {
    throw std::out_of_range("Empty List");
  }
  return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const {
  if (empty()) {
    throw std::out_of_range("Empty List");
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_ ) {
    return NULL; 
  }
  Item* current = head_;
  size_t index = 0; 
  while (current != NULL) {
    size_t listLength = current->last - current->first;
    if (index + listLength <= loc) {
      index = index + listLength;
      current = current->next;
    }
    else{
      size_t listLocation = current->first + loc - index;
      return &(current->val[listLocation]);
    }
  }
  return NULL; 
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

/* Behorende bij Programmeertechnieken huiswerk 3: unit testing.
 */

#include "mystack.h"
#define BOOST_TEST_MODULE MyStackTest
#include <boost/test/unit_test.hpp>

#include <vector>

/* Explicitly instantiate template classes for the sake of code
 * coverage generation.
 * http://stackoverflow.com/a/19792966
 */
template class MyStack<int>;
template void MyStack<int>::push_multiple<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);


BOOST_AUTO_TEST_SUITE(mystack_test)

BOOST_AUTO_TEST_CASE(mystack_push)
{
  MyStack<int> stack;
  stack.push(10);
  BOOST_CHECK_EQUAL(stack.peek(), 10);
  BOOST_CHECK_EQUAL(stack.size(), 1UL);
  stack.push(20);
  BOOST_CHECK_EQUAL(stack.peek(), 20);
  BOOST_CHECK_EQUAL(stack.size(), 2UL);
  stack.push(30);
  BOOST_CHECK_EQUAL(stack.peek(), 30);
  BOOST_CHECK_EQUAL(stack.size(), 3UL);
  stack.push(40);
  BOOST_CHECK_EQUAL(stack.peek(), 40);
  BOOST_CHECK_EQUAL(stack.size(), 4UL);
}

/* TODO: more tests here ... */
BOOST_AUTO_TEST_CASE(mystack_push_multiple)
{
  MyStack<int> stack;
  std::vector<int> vector{10, 20, 30, 40};
  stack.push_multiple(vector.begin(), vector.end());
  stack.pop();
  BOOST_CHECK_EQUAL(stack.peek(), 30);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.peek(), 20);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.peek(), 10); 
  BOOST_CHECK_EQUAL(stack.size(), 1UL);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.is_empty(), true);
}

BOOST_AUTO_TEST_CASE(mystack_push_multiple2)
{
  MyStack<int> stack;
  stack.push_multiple({10, 20, 30, 40});
  BOOST_CHECK_EQUAL(stack.size(), 4UL);
  BOOST_CHECK_EQUAL(stack.peek(), 40);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.peek(), 30);
  BOOST_CHECK_EQUAL(stack.size(), 3UL);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.peek(), 20);
  BOOST_CHECK_EQUAL(stack.size(), 2UL);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.size(), 1UL);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.is_empty(), true);
 }

BOOST_AUTO_TEST_CASE(mystack_peek)
{
  MyStack<int> stack;
  //BOOST_CHECK_THROW(stack.peek(), std::out_of_range_error);
  stack.push(10);
  BOOST_CHECK_EQUAL(stack.peek(), 10);
  stack.push(20);
  BOOST_CHECK_EQUAL(stack.peek(), 20);
  BOOST_CHECK_EQUAL(stack.size(), 2UL);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.size(), 1UL);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.is_empty(), true);
 // BOOST_CHECK_THROW(stack.peek(),std::out_of_range_error);
}

BOOST_AUTO_TEST_CASE(mystack_pop)
{
  MyStack<int> stack;
  stack.push(30);
  stack.push(40);
  stack.push(50);
  BOOST_CHECK_EQUAL(stack.pop(), 50);
  BOOST_CHECK_EQUAL(stack.pop(), 40);
  BOOST_CHECK_EQUAL(stack.pop(), 30);
//  BOOST_CHECK_THROW(stack.pop(), std::out_of_range());
}

BOOST_AUTO_TEST_CASE(mystack_clear)
{
  MyStack<int> stack;
  stack.push_multiple({30,40,50});
  BOOST_CHECK_EQUAL(stack.size(), 3UL);
  stack.clear();
  BOOST_CHECK_EQUAL(stack.size(), 0UL);
  stack.clear();
  BOOST_CHECK_EQUAL(stack.size(), 0UL);
}

BOOST_AUTO_TEST_CASE(mystack_size)
{
  MyStack<int> stack;
  stack.push(10);
  BOOST_CHECK_EQUAL(stack.size(), 1UL);
  stack.push(20);
  BOOST_CHECK_EQUAL(stack.size(), 2UL);
  stack.pop();
  stack.pop();
  BOOST_CHECK_EQUAL(stack.size(), 0UL);

}

BOOST_AUTO_TEST_CASE(mystack_is_empty)
{  
  MyStack<int> stack;
  BOOST_CHECK_EQUAL(stack.is_empty(), true);
  stack.push(10);
  BOOST_CHECK_EQUAL(stack.is_empty(), false);
  stack.pop();
  BOOST_CHECK_EQUAL(stack.is_empty(), true);
}

BOOST_AUTO_TEST_SUITE_END()

#include <gtest.h>
#include "Polynom.h"

TEST(Monom, can_create_monom)
{
  unsigned int arr[] = { 1, 2, 3 };
  ASSERT_NO_THROW(TMonom monom(3, arr, 1));
}

TEST(Monom, throw_when_create_monom_with_zero_size)
{
  unsigned arr[] = { 1, 2, 3 };
  ASSERT_ANY_THROW(TMonom monom(0, arr, 1));
}

TEST(Monom, throw_when_create_monom_with_negative_size)
{
  unsigned arr[] = { 1, 2, 3 };
  ASSERT_ANY_THROW(TMonom monom(-1, arr, 1));
}

TEST(Monom, can_create_copy_monom)
{
  unsigned arr[] = { 1, 2, 3 };
  TMonom monom(3, arr, 1);
  ASSERT_NO_THROW(TMonom copy(monom));
}

TEST(Monom, can_set_and_get_next)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 3, 3 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 2);
  ASSERT_NO_THROW(monom1.SetNext(&monom2));
  ASSERT_EQ(&monom2, monom1.GetNext());
}

TEST(Monom, can_set_and_get_c)
{
  unsigned arr[] = { 1, 2, 3 };
  TMonom monom(3, arr, 2);
  ASSERT_NO_THROW(monom.SetC(22));
  ASSERT_EQ(22, monom.GetC());
}

TEST(Monom, can_set_and_get_power)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 4, 5, 6 };
  TMonom monom(3, arr1, 1);
  ASSERT_NO_THROW(monom.SetPower(arr2));
  ASSERT_EQ(arr2[0], monom.GetPower()[0]);
  ASSERT_EQ(arr2[1], monom.GetPower()[1]);
  ASSERT_EQ(arr2[2], monom.GetPower()[2]);
}

TEST(Monom, can_get_n)
{
  unsigned arr[] = { 1, 2, 3 };
  TMonom monom(3, arr, 1);
  ASSERT_EQ(3, monom.GetN());
}

TEST(Monom, can_use_assignment_operator)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 4, 5 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 4);
  ASSERT_NO_THROW(monom1 = monom2);  
  ASSERT_EQ(4, monom1.GetC());
  ASSERT_EQ(3, monom1.GetPower()[0]);
  ASSERT_EQ(4, monom1.GetPower()[1]);
  ASSERT_EQ(5, monom1.GetPower()[2]);
}

TEST(Monom, throws_when_assignment_monoms_with_different_number_variables)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 4, 5, 6 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(4, arr2, 4);
  ASSERT_ANY_THROW(monom1 = monom2);
}

TEST(Monom, can_add_equal_monoms)
{
  unsigned arr[] = { 1, 2, 3 };
  TMonom monom1(3, arr, 4);
  TMonom monom2(3, arr, 3);
  ASSERT_NO_THROW(monom1 + monom2);
  TMonom result(3, 0, 0);
  result = monom1 + monom2;
  ASSERT_EQ(7, result.GetC());
}

TEST(Monom, throws_when_add_monoms_with_different_number_variables)
{
  TMonom monom1(3, 0, 1);
  TMonom monom2(4, 0, 3);
  ASSERT_ANY_THROW(monom1 + monom2);
}

TEST(Monom, throws_when_add_monoms_with_different_powers)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 2, 3 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(4, arr2, 3);
  ASSERT_ANY_THROW(monom1 + monom2);
}

TEST(Monom, can_substract_equal_monoms)
{
  unsigned arr[] = { 1, 2, 3 };
  TMonom monom1(3, arr, 4);
  TMonom monom2(3, arr, 3);
  ASSERT_NO_THROW(monom1 - monom2);
  TMonom result(3, 0, 0);
  result = monom1 - monom2;
  ASSERT_EQ(1, result.GetC());
}

TEST(Monom, throws_when_substract_monoms_with_different_number_variables)
{
  TMonom monom1(3, 0, 1);
  TMonom monom2(4, 0, 3);
  ASSERT_ANY_THROW(monom1 - monom2);
}

TEST(Monom, throws_when_substract_monoms_with_different_powers)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 2, 3 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(4, arr2, 3);
  ASSERT_ANY_THROW(monom1 - monom2);
}

TEST(Monom, can_multiply_equal_monoms)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 2, 3 };
  TMonom monom1(3, arr1, 2);
  TMonom monom2(3, arr2, 3);
  ASSERT_NO_THROW(monom1 * monom2);
  TMonom result(3, 0, 0);
  result = monom1 * monom2;
  ASSERT_EQ(6, result.GetC());
  ASSERT_EQ(4, result.GetPower()[0]);
  ASSERT_EQ(4, result.GetPower()[1]);
  ASSERT_EQ(6, result.GetPower()[2]);
}

TEST(Monom, throws_when_multiply_monoms_with_different_number_variables)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 2, 3, 5 };
  TMonom monom1(3, arr1, 2);
  TMonom monom2(4, arr2, 3);
  ASSERT_ANY_THROW(monom1 * monom2);
}

TEST(Monom, can_check_for_equality)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 2, 3 };
  TMonom monom1(3, arr1, 4);
  TMonom monom2(3, arr2, 4);
  TMonom monom3(3, arr2, 4);
  ASSERT_TRUE(monom2 == monom3);
  ASSERT_FALSE(monom1 == monom2);
}

TEST(Monom, throws_when_check_for_equality_with_different_number_variables)
{
  TMonom monom1(3, 0, 1);
  TMonom monom2(4, 0, 1);
  ASSERT_ANY_THROW(monom1 == monom2);
}

TEST(Monom, can_compare_equal_monoms)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 2, 3 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 2);
  TMonom monom3(3, arr2, 3);
  ASSERT_TRUE(monom1 < monom2);
  ASSERT_FALSE(monom1 > monom2);
}

TEST(Monom, throws_when_compare_monoms_with_different_number_variables)
{
  TMonom monom1(3, 0, 1);
  TMonom monom2(4, 0, 2);
  ASSERT_ANY_THROW(monom1 > monom2);
  ASSERT_ANY_THROW(monom1 < monom2);
}

TEST(Polynom, can_create_polynom)
{
  ASSERT_NO_THROW(TPolynom poly(3));
}

TEST(Polynom, throws_when_create_polynom_with_negative_size)
{
  ASSERT_ANY_THROW(TPolynom P(-3));
}

TEST(Polynom, can_create_copy_polynom)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 3, 2, 3 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 2);
  TPolynom poly(3);
  poly += monom1;
  poly += monom2;
  ASSERT_NO_THROW(TPolynom polycopy(poly));
  TPolynom polycopy(poly);
  ASSERT_TRUE(polycopy == poly);
}

TEST(Polynom, can_use_assignment_operator_poly)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 1, 0, 3 };
  unsigned arr3[] = { 4, 5, 6 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 2);
  TMonom monom3(3, arr3, 3);
  TMonom monom4(3, arr1, 0);
  TPolynom poly1(3);
  poly1 += monom1;
  poly1 += monom4;
  TPolynom poly2(3);
  poly2 += monom2;
  poly2 += monom3;
  ASSERT_NO_THROW(poly1 = poly2);
  TMonom *_monom = poly1.GetStart();
  ASSERT_TRUE(*_monom == monom3);
  ASSERT_EQ(3, _monom->GetC());
  _monom = _monom->GetNext();
  ASSERT_TRUE(*_monom == monom2);
  ASSERT_EQ(2, _monom->GetC());
  _monom = _monom->GetNext();
  ASSERT_TRUE(_monom == 0);
}

TEST(Polynom, can_add_monom_to_poly)
{
  unsigned arr1[] = { 1, 0, 3 };
  unsigned arr2[] = { 4, 5, 6 };
  TMonom monom1(3, arr1, 2);
  TMonom monom2(3, arr2, 3);
  TPolynom poly(3);
  poly += monom1;
  poly += monom2;
  TMonom *_monom = poly.GetStart();
  ASSERT_TRUE(*_monom == monom2);
  ASSERT_EQ(_monom->GetC(), 3);
  _monom = _monom->GetNext();
  ASSERT_TRUE(*_monom == monom1);
  ASSERT_EQ(_monom->GetC(), 2);
  _monom = _monom->GetNext();
  ASSERT_TRUE(_monom == 0);
}

TEST(Polynom, throws_when_add_monom_to_poly_with_different_number_variables)
{
  TPolynom poly(3);
  TMonom monom(4, 0, 1);
  ASSERT_ANY_THROW(poly += monom);
}

TEST(Polynom, can_add_polynoms_with_equal_size)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 1, 0, 3 };
  unsigned arr3[] = { 4, 5, 6 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 2);
  TMonom monom3(3, arr3, 3);

  TPolynom poly1(3);
  poly1 += monom1;
  poly1 += monom2;
  TPolynom poly2(3);
  poly2 += monom1;
  poly2 += monom3;
  ASSERT_NO_THROW(poly1 + poly2);
  TPolynom result(3);
  result = poly1 + poly2;
  TMonom* _monom = result.GetStart();
  ASSERT_TRUE(*_monom == monom3);
  _monom = _monom->GetNext();
  ASSERT_TRUE(*_monom == monom1);
  _monom = _monom->GetNext();
  ASSERT_TRUE(*_monom == monom2);
  _monom = _monom->GetNext();
  ASSERT_TRUE(_monom == 0);
}

TEST(Polynom, throws_when_add_polynoms_with_different_number_variables)
{
  TPolynom poly1(4);
  TPolynom poly2(3);
  ASSERT_ANY_THROW(poly1 + poly2);
}

TEST(Polynom, can_check_for_equality_poly)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 1, 0, 3 };
  unsigned arr3[] = { 4, 5, 6 };
  unsigned arr4[] = { 3, 2, 3 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 2);
  TMonom monom3(3, arr3, 3);
  TMonom monom4(3, arr4, 3);

  TPolynom poly1(3);
  poly1 += monom1;
  poly1 += monom3;
  TPolynom poly2(3);
  poly2 += monom2;
  poly2 += monom4;
  ASSERT_FALSE(poly1 == poly2);
  poly2 = poly1;
  ASSERT_TRUE(poly1 == poly2);
}

TEST(Polynom, throws_when_check_for_equality_polynoms_with_different_number_variables)
{
  TPolynom poly1(3);
  TPolynom poly2(4);
  ASSERT_ANY_THROW(poly1 == poly2);
}

TEST(Polynom, can_multiply_polynoms)
{
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 1, 0, 3 };
  unsigned arr3[] = { 4, 5, 6 };
  TMonom monom1(3, arr1, 1);
  TMonom monom2(3, arr2, 2);
  TMonom monom3(3, arr3, 3);
  TMonom monom4(3, arr1, 0);
  TPolynom poly1(3);
  poly1 += monom1;
  poly1 += monom4;
  TPolynom poly2(3);
  poly2 += monom2;
  poly2 += monom3;
  ASSERT_NO_THROW(poly1 * poly2);
  TPolynom result(3);
  result = poly1 * poly2;
  TMonom *_monom = result.GetStart();
  TMonom monom12 = monom1 * monom2;
  TMonom monom13 = monom1 * monom3;
  ASSERT_TRUE(*_monom == monom13);
  ASSERT_EQ(_monom->GetC(), 3);
  _monom = _monom->GetNext();
  ASSERT_TRUE(*_monom == monom12);
  ASSERT_EQ(_monom->GetC(), 2);
  _monom = _monom->GetNext();
  ASSERT_TRUE(_monom == 0);
}

TEST(Polynom, throws_when_multiply_polynoms_with_different_number_variables)
{
  TPolynom poly1(3);
  TPolynom poly2(4);
  ASSERT_ANY_THROW(poly1 * poly2);
}
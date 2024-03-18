#include "TPolinom.h"
#include "THeadList.h"
#include <gtest.h>

TEST(TPolinom, Created_polinom_is_empty) {
	TPolinom p;
	EXPECT_TRUE(p.IsEmpty());
}

TEST(TPolinom, Created_polinom_with_one_monom_is_not_empty) {
	TPolinom p;
	TMonom m(2.0, 2, 2, 2);
	p.AddMonom(m);
	EXPECT_FALSE(p.IsEmpty());
}

TEST(TPolinom, Coefficients_add_up_if_degrees_are_equal) {
	TPolinom p;
	TMonom a(2.0, 1, 1, 1);
	TMonom b(3.0, 1, 1, 1);
	p.AddMonom(a);
	p.AddMonom(b);
	p.Reset();
	EXPECT_TRUE((p.monoms.GetLength() == 1) && (p.monoms.GetCurrentItem().GetCoef() == 5.0));
}

TEST(TPolinom, Coefficients_dont_add_up_if_degrees_are_different) {
	TPolinom p;
	TMonom a(2.0, 2, 1, 1);
	TMonom b(3.0, 1, 1, 1);
	p.AddMonom(a);
	p.AddMonom(b);
	p.Reset();
	EXPECT_FALSE((p.monoms.GetLength() == 1) && (p.monoms.GetCurrentItem().GetCoef() == 5.0));
}

TEST(TPolinom, Monom_delete_if_coefficient_equal_zero) {
}

TEST(TPolinom, Can_not_get_monom_from_empty_polinom) {
}

TEST(TPolinom, Copied_polinom_is_equal_copiable) {
}

TEST(TPolinom, Assigned_polinom_is_equal_assignable) {
}

TEST(TPolinom, Correct_adding_operator) {
}

TEST(TPolinom, Correct_constant_multiply) {
}

TEST(TPolinom, Correct_monom_multiply) {
}

TEST(TPolinom, Correct_polinom_enter) {
}

TEST(TPolinom, Correct_multiply_polinom1) {
}

TEST(TPolinom, Correct_multiply_polinom2) {
}

TEST(TPolinom, Correct_multiply_polinom3) {
}

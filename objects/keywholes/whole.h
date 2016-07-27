
#ifndef _WHOLE_H_
#define _WHOLE_H_

struct Whole_01{
	shape whole_esc_01;
	shape whole_ent_01;
	shape whole_w_01;
	shape whole_a_01;
	shape whole_s_01;
	shape whole_d_01;
	shape whole_up_01;
	shape whole_down_01;
	shape whole_left_01;
	shape whole_right_01;
};
typedef struct Whole_01 whole_01;

struct Whole_02{
	shape whole_esc_02;
	shape whole_ent_02;
	shape whole_w_02;
	shape whole_a_02;
	shape whole_s_02;
	shape whole_d_02;
	shape whole_up_02;
	shape whole_down_02;
	shape whole_left_02;
	shape whole_right_02;
};
typedef struct Whole_02 whole_02;

struct Whole_03{
	shape whole_esc_03;
	shape whole_ent_03;
	shape whole_w_03;
	shape whole_a_03;
	shape whole_s_03;
	shape whole_d_03;
	shape whole_up_03;
	shape whole_down_03;
	shape whole_left_03;
	shape whole_right_03;
};
typedef struct Whole_03 whole_03;

whole_01 init_whole_01();
whole_02 init_whole_02();
whole_03 init_whole_03();

void del_whole_01(whole_01);
void del_whole_02(whole_02);
void del_whole_03(whole_03);

shape whole_a_01();
shape whole_a_02();
shape whole_a_03();
shape whole_d_01();
shape whole_d_02();
shape whole_d_03();
shape whole_down_01();
shape whole_down_02();
shape whole_down_03();
shape whole_ent_01();
shape whole_ent_02();
shape whole_ent_03();
shape whole_esc_01();
shape whole_esc_02();
shape whole_esc_03();
shape whole_left_01();
shape whole_left_02();
shape whole_left_03();
shape whole_right_01();
shape whole_right_02();
shape whole_right_03();
shape whole_s_01();
shape whole_s_02();
shape whole_s_03();
shape whole_up_01();
shape whole_up_02();
shape whole_up_03();
shape whole_w_01();
shape whole_w_02();
shape whole_w_03();

#endif


#include "../../stack/stack.h"
#include "keypurp.h"

shape keypurp_a_01(){
	
	short x[] = { 120, 122, 125, 188, 191, 193, 193, 193, 189, 182, 180, 175, 165, 146, 140, 134, 130, 122, 121, 120 };
	short y[] = { 419, 422, 423, 423, 421, 418, 395, 363, 355, 344, 341, 339, 339, 339, 338, 339, 344, 361, 394, 409 };
	short points = 20;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_a_02(){
	
	short x[] = { 121, 125, 188, 191, 193, 193, 193, 192, 182, 180, 176, 168, 155, 145, 139, 134, 131, 122, 121, 120, 119 };
	short y[] = { 421, 423, 423, 421, 418, 392, 363, 360, 344, 341, 338, 339, 340, 339, 338, 339, 343, 362, 388, 406, 417 };
	short points = 21;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_a_03(){
	
	short x[] = { 120, 122, 126, 188, 191, 193, 193, 193, 191, 188, 183, 180, 175, 167, 144, 138, 132, 130, 122, 121, 120 };
	short y[] = { 419, 422, 423, 423, 421, 418, 391, 364, 360, 354, 345, 341, 338, 339, 339, 339, 340, 345, 361, 371, 406 };
	short points = 21;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_d_01(){
	
	short x[] = { 272, 274, 277, 303, 338, 343, 345, 345, 345, 345, 345, 345, 340, 335, 333, 330, 326, 319, 308, 295, 291, 285, 282, 274, 273, 273, 272, 272 };
	short y[] = { 419, 422, 423, 423, 423, 422, 418, 410, 398, 377, 367, 363, 355, 345, 342, 340, 339, 339, 340, 339, 338, 339, 344, 360, 364, 389, 404, 415 };
	short points = 28;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_d_02(){
	
	short x[] = { 273, 276, 281, 306, 330, 340, 343, 345, 345, 345, 345, 344, 337, 334, 330, 327, 320, 308, 296, 290, 284, 282, 275, 273, 273, 272, 271 };
	short y[] = { 419, 422, 423, 422, 423, 423, 421, 418, 403, 376, 365, 362, 350, 344, 339, 338, 339, 339, 339, 338, 340, 344, 359, 363, 393, 413, 417 };
	short points = 27;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_d_03(){

	short x[] = { 274, 278, 306, 336, 342, 346, 345, 346, 344, 340, 334, 332, 329, 324, 318, 297, 292, 289, 285, 282, 274, 274, 272, 272, 271, 273 };
	short y[] = { 422, 423, 423, 423, 421, 417, 399, 367, 361, 353, 344, 341, 339, 339, 340, 339, 339, 338, 340, 344, 360, 365, 397, 411, 417, 420 };
	short points = 26;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_down_01(){


	short x[] = { 513, 516, 534, 564, 579, 582, 584, 584, 584, 583, 573, 571, 568, 556, 537, 532, 525, 522, 514, 512, 512, 511, 510 };
	short y[] = { 421, 423, 423, 423, 423, 421, 418, 407, 364, 361, 344, 341, 339, 339, 339, 339, 340, 343, 359, 365, 395, 408, 418 };
	short points = 23;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_down_02(){


	short x[] = { 512, 516, 537, 562, 578, 582, 584, 584, 584, 582, 574, 570, 565, 558, 537, 529, 523, 520, 514, 512, 511, 510 };
	short y[] = { 421, 424, 423, 423, 423, 421, 418, 406, 364, 360, 345, 341, 339, 339, 339, 339, 341, 346, 359, 364, 406, 418 };
	short points = 22;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_down_03(){

	short x[] = { 516, 578, 582, 584, 584, 584, 581, 573, 570, 566, 554, 535, 529, 524, 521, 514, 512, 512, 511, 511, 513 };
	short y[] = { 423, 423, 421, 417, 372, 363, 358, 344, 340, 339, 339, 339, 339, 340, 344, 360, 364, 395, 409, 419, 421 };
	short points = 21;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_ent_01(){

	short x[] = { 596, 698, 703, 706, 705, 697, 695, 693, 689, 685, 682, 675, 660, 639, 617, 603, 594, 589, 585, 579, 575, 574, 572, 571, 570, 575, 586, 591, 591, 590, 589, 590, 592 };
	short y[] = { 193, 194, 192, 190, 178, 123, 111, 99, 86, 72, 66, 65, 67, 68, 67, 65, 64, 64, 67, 84, 94, 102, 116, 129, 136, 139, 139, 143, 150, 171, 184, 189, 192 };
	short points = 33;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_ent_02(){


	short x[] = { 648, 702, 704, 706, 705, 702, 697, 695, 694, 690, 685, 682, 675, 662, 645, 621, 602, 595, 590, 585, 579, 575, 573, 572, 570, 571, 576, 589, 592, 590, 589, 589, 596 };
	short y[] = { 194, 194, 192, 190, 181, 156, 127, 107, 100, 87, 72, 66, 65, 67, 67, 67, 65, 64, 63, 67, 82, 94, 102, 118, 132, 136, 139, 140, 144, 162, 180, 189, 193 };
	short points = 33;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_ent_03(){

	short x[] = { 591, 596, 648, 701, 704, 706, 705, 700, 696, 695, 693, 689, 686, 683, 678, 667, 646, 625, 604, 595, 591, 585, 579, 575, 574, 572, 570, 571, 576, 588, 591, 590, 589, 588 };
	short y[] = { 190, 193, 193, 194, 192, 190, 180, 148, 115, 105, 97, 83, 74, 68, 65, 66, 67, 67, 65, 64, 64, 66, 85, 94, 102, 116, 130, 137, 139, 140, 143, 161, 181, 188 };
	short points = 34;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_esc_01(){

	short x[] = { 48, 111, 116, 116, 105, 102, 98, 81, 60, 56, 53, 45, 43, 45 };
	short y[] = { 109, 109, 104, 50, 30, 26, 24, 26, 25, 26, 29, 48, 104, 107 };
	short points = 14;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_esc_02(){

	short x[] = { 44, 44, 42, 44, 48, 111, 114, 116, 117, 115, 105, 103, 98, 89, 69, 64, 59, 54, 53, 45 };
	short y[] = { 50, 70, 104, 107, 109, 109, 107, 104, 50, 47, 29, 27, 25, 25, 25, 24, 24, 27, 31, 46 };
	short points = 20;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_esc_03(){

	short x[] = { 110, 113, 116, 116, 116, 115, 105, 102, 98, 90, 68, 63, 58, 54, 45, 43, 47 };
	short y[] = { 109, 108, 104, 82, 51, 46, 29, 26, 25, 25, 25, 24, 24, 29, 47, 105, 109 };
	short points = 17;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_left_01(){

	short x[] = { 435, 437, 440, 503, 506, 508, 508, 507, 502, 497, 495, 490, 484, 470, 458, 452, 449, 446, 437, 436, 436, 435, 434 };
	short y[] = { 419, 421, 423, 423, 421, 418, 364, 360, 352, 344, 341, 338, 339, 340, 339, 339, 340, 343, 361, 366, 393, 408, 414 };
	short points = 23;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_left_02(){

	short x[] = { 440, 503, 506, 508, 508, 508, 508, 507, 497, 495, 491, 483, 471, 459, 453, 448, 445, 438, 437, 436, 435, 435, 437 };
	short y[] = { 423, 423, 422, 418, 410, 383, 364, 361, 344, 341, 339, 339, 339, 339, 338, 340, 345, 360, 364, 396, 409, 418, 421 };
	short points = 23;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_left_03(){

	short x[] = { 436, 439, 444, 471, 502, 506, 508, 508, 508, 508, 507, 504, 497, 495, 490, 482, 459, 457, 450, 447, 444, 438, 436, 435, 435, 434 };
	short y[] = { 421, 423, 423, 423, 423, 422, 418, 414, 392, 363, 361, 355, 344, 340, 339, 340, 340, 339, 338, 340, 345, 359, 364, 396, 409, 418 };
	short points = 26;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_right_01(){

	short x[] = { 590, 593, 619, 650, 656, 659, 660, 660, 660, 660, 657, 650, 647, 642, 634, 614, 606, 600, 597, 590, 589, 587, 587, 586 };
	short y[] = { 422, 423, 423, 423, 423, 420, 417, 396, 368, 363, 358, 345, 341, 339, 339, 339, 338, 340, 345, 358, 362, 393, 413, 418 };
	short points = 24;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_right_02(){

	short x[] = { 588, 592, 612, 654, 657, 660, 660, 660, 660, 659, 657, 648, 645, 640, 635, 623, 609, 603, 599, 595, 591, 589, 588, 587, 587 };
	short y[] = { 421, 423, 422, 423, 422, 418, 416, 376, 365, 361, 358, 343, 340, 339, 339, 340, 339, 339, 341, 347, 358, 363, 395, 409, 418 };
	short points = 25;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_right_03(){

	short x[] = { 589, 592, 606, 638, 655, 658, 660, 660, 660, 660, 660, 658, 651, 649, 646, 641, 634, 615, 607, 601, 597, 593, 589, 588, 587, 586, 586 };
	short y[] = { 421, 423, 423, 423, 423, 421, 418, 410, 392, 368, 364, 359, 349, 343, 340, 339, 339, 339, 338, 339, 343, 353, 362, 386, 400, 408, 417 };
	short points = 27;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_s_01(){

	short x[] = { 202, 263, 267, 269, 269, 268, 269, 267, 259, 255, 251, 242, 221, 214, 208, 205, 198, 197, 196, 195, 198 };
	short y[] = { 423, 423, 421, 418, 408, 383, 363, 359, 344, 340, 339, 339, 339, 339, 341, 348, 361, 387, 407, 418, 421 };
	short points = 21;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_s_02(){

	short x[] = { 201, 265, 268, 270, 269, 269, 268, 258, 255, 250, 237, 222, 214, 210, 206, 198, 197, 196, 196, 198 };
	short y[] = { 423, 423, 420, 418, 396, 363, 361, 344, 340, 339, 340, 340, 339, 340, 344, 361, 364, 396, 418, 421 };
	short points = 20;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_s_03(){

	short x[] = { 195, 200, 219, 247, 263, 267, 269, 269, 269, 267, 258, 256, 251, 242, 222, 216, 210, 207, 199, 198, 197, 196, 196 };
	short y[] = { 419, 423, 423, 423, 423, 421, 418, 388, 364, 360, 344, 341, 339, 339, 339, 339, 339, 344, 360, 363, 379, 400, 409 };
	short points = 23;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_up_01(){

	short x[] = { 513, 517, 541, 578, 582, 584, 584, 584, 584, 580, 573, 570, 564, 557, 536, 530, 523, 519, 513, 512, 512, 511, 510 };
	short y[] = { 355, 357, 357, 357, 355, 352, 327, 304, 297, 290, 278, 274, 273, 274, 273, 272, 274, 282, 294, 300, 329, 342, 352 };
	short points = 23;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_up_02(){

	short x[] = { 513, 516, 539, 572, 580, 582, 584, 583, 584, 583, 581, 575, 572, 570, 565, 557, 538, 532, 525, 521, 514, 512, 512, 511, 511, 510 };
	short y[] = { 355, 357, 357, 357, 356, 354, 351, 329, 302, 296, 291, 282, 277, 274, 273, 273, 273, 272, 273, 277, 292, 299, 318, 333, 345, 350 };
	short points = 26;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_up_03(){

	short x[] = { 516, 547, 579, 582, 585, 584, 584, 584, 580, 574, 570, 566, 558, 536, 531, 526, 521, 519, 513, 512, 512, 510, 511, 513 };
	short y[] = { 357, 357, 357, 355, 352, 337, 317, 297, 291, 279, 274, 273, 274, 274, 273, 273, 276, 283, 296, 317, 334, 346, 353, 355 };
	short points = 24;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_w_01(){

	short x[] = { 195, 196, 197, 197, 199, 204, 208, 212, 215, 221, 243, 250, 255, 258, 269, 269, 268, 264, 201, 198 };
	short y[] = { 352, 342, 318, 299, 292, 281, 275, 273, 272, 273, 273, 272, 274, 278, 297, 350, 354, 357, 357, 355 };
	short points = 20;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_w_02(){

	short x[] = { 195, 199, 203, 264, 268, 269, 269, 269, 266, 258, 256, 251, 243, 229, 220, 215, 210, 206, 198, 197, 196 };
	short y[] = { 352, 356, 357, 357, 354, 351, 337, 298, 292, 278, 274, 273, 273, 273, 273, 272, 273, 277, 295, 299, 330 };
	short points = 21;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}

shape keypurp_w_03(){

	short x[] = { 195, 199, 205, 263, 267, 270, 269, 269, 267, 260, 258, 255, 250, 243, 232, 220, 213, 209, 206, 198, 197, 197, 195 };
	short y[] = { 352, 356, 357, 357, 355, 351, 340, 298, 292, 281, 277, 274, 272, 273, 273, 273, 272, 274, 279, 294, 297, 323, 345 };
	short points = 23;
	short color[] = {160, 130, 172, 255};
	short z = 1;
	
	int i;
	for(i = points; i >= 0; i--){
		x[i] += 10;
		y[i] += 10;
	}
	
	shape g_shape = init_shape(x, y, points, color, z);

	return g_shape;
}





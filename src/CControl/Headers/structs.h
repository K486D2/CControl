/*
 * structs.h
 *
 *  Created on: 20 Juli. 2023
 *      Author: Daniel Mårtensson
 */

#ifndef CCONTROL_HEADERS_STRUCTS_H_
#define CCONTROL_HEADERS_STRUCTS_H_

/* For imshow.c and imread.c */
typedef struct {
	size_t width;
	size_t height;
	uint8_t max_gray_value;
	uint8_t* pixels;
}PGM;

/* For fisherfaces.c */
typedef struct {
	size_t row;
	size_t column;
	size_t* class_id;
	float* data;
}FISHER_MODEL;

/* For fisherfaces.c */
typedef struct {
	/* For face detection */
	size_t pooling_size;
	POOLING_METHOD pooling_method;

	/* For object detection */
	float sigma1;
	float sigma2;
	uint8_t threshold_sobel;
	uint8_t threshold_fast;
	FAST_METHOD fast_method;

	/* Source to the data */
	char folder_path[256];

	/* Type of detection */
	FISHER_FACES_DETECTION fisher_faces_detection;

	/* Remove outliers settings */
	bool remove_outliers;
	float epsilon;
	size_t min_pts;

	/* Kernel PCA settings */
	size_t components_pca;
	float kernel_parameters[2];
	KERNEL_METHOD kernel_method;

	/* Neural network settings */
	float C;
	float lambda;
}FISHER_FACES_SETTINGS;

/* For fast.c */
typedef struct {
	int x;
	int y;
} FAST_XY;

#endif /* !CCONTROL_HEADERS_STRUCTS_H_ */
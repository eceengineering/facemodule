#ifndef FACEMODULE_H_
#define FACEMODULE_H_

#ifdef __cplusplus
extern "C" {
#endif

struct facemodule_arguments 
{
	int width;
	int height;
};

/* These functions return ERROR value as an integer */
int facemodule_init 	(struct facemodule_arguments *arg);
int facemodule_close	(void);
int facemodule_data	(char *data);
int facemodule_detect	(void *result);

#ifdef __cplusplus
}
#endif

#endif /* FACEMODULE_H_ */

#include "fir.h"
#include <stdio.h>
void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {

    for (int i = 0; i < N; i++) {
        inputbuffer[i] = 0;
    }

}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
	initfir();
    int i, j;
    int result;
/*
    for (i = 0; i < N; i++) {
        inputbuffer[i] = ;
    }
*/
    for (i = 0; i < N; i++) {
        result = 0;
        for (j = 0; j < N; j++) {
            if (i - j >= 0) {
                result += taps[j] * inputbuffer[i - j];
            }
        }
        outputsignal[i] = result;
    }
/*
    // 打印输出信号
    printf("Output Signal: ");
    for (i = 0; i < N; i++) {
        printf("%d ", outputsignal[i]);
    }
    printf("\n");
*/
return outputsignal;
}
		

/*
 * Kiwi.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef KIWI_H_
#define KIWI_H_

#include "TextureRenderer.h"

class Kiwi
{
    public:
        float moveSpeed;
        int right;
        int down;

        Kiwi(void);
        Kiwi(int, int, float);
        ~Kiwi(void);

        void draw();
        void update(float);
    private:
        float x;
        float y;
};

#endif /* KIWI_H_ */

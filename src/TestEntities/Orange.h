/*
 * Orange.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef ORANGE_H_
#define ORANGE_H_

#include "TextureRenderer.h"

class Orange
{
    public:
        bool up;
        bool down;
        bool left;
        bool right;

        float moveSpeed;

        Orange(void);
        ~Orange(void);

        void draw();
        void Update();
        void Move(float);

        void moveUp(bool);
        void moveDown(bool);
        void moveLeft(bool);
        void moveRight(bool);

    private:
        float x;
        float y;
};
#endif /* ORANGE_H_ */

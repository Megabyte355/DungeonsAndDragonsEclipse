/*
 * Orange.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef ORANGE_H_
#define ORANGE_H_

#include "Textures.h"

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

        void Draw();
        void Update();
        void Move(float);

        void MoveUp(bool);
        void MoveDown(bool);
        void MoveLeft(bool);
        void MoveRight(bool);

    private:
        float x;
        float y;
};
#endif /* ORANGE_H_ */

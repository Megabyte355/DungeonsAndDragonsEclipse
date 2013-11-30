/*
 * NumericTextField.h
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#ifndef NUMERICTEXTFIELD_H_
#define NUMERICTEXTFIELD_H_

#include "TextField.h"

class NumericTextField : public virtual TextField
{
    public:
        NumericTextField(int,int,int,int,int);
        virtual ~NumericTextField();

        void handleEvents(SDL_Event &) override;
    private:
        unsigned int maxLength;
};

#endif /* NUMERICTEXTFIELD_H_ */

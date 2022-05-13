#pragma once
#include "PatternBase.h"
class PatternFlower :
    public PatternBase
{
public:
    PatternFlower(int Interval, int size);
    PatternResult Next(PatternParam Param);
    void SetAngleOffset(int newOffset);         // �Ѿ� ��� ���� ����
private:
    int degree;          // ����
    int degree2;
    int step;

    int AngleOffset;
};


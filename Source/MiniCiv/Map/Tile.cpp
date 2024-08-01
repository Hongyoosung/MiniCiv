// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"

void ATile::InitializeResources()
{
    switch (TileType)
    {
    case ETileType::Plains:
        PrimaryResourceValue = FMath::RandRange(3, 5);  // �ķ�
        SecondaryResourceValue = FMath::RandRange(0, 1);  // �����
        break;
    case ETileType::Forest:
        PrimaryResourceValue = FMath::RandRange(3, 5);  // �����
        SecondaryResourceValue = FMath::RandRange(1, 2);  // �ķ�
        break;
    case ETileType::Mountain:
        PrimaryResourceValue = FMath::RandRange(3, 5);  // ����
        SecondaryResourceValue = FMath::RandRange(0, 1);  // �����
        break;
    case ETileType::Water:
        PrimaryResourceValue = FMath::RandRange(2, 4);  // ��
        SecondaryResourceValue = 0;  // �ʱ⿡�� �߰� �ڿ� ����
        break;
    }
}

void ATile::GetResourceProduction(int32& OutFood, int32& OutProduction, int32& OutScience, int32& OutGold)
{
    OutFood = OutProduction = OutScience = OutGold = 0;

    switch (TileType)
    {
    case ETileType::Plains:
        OutFood = PrimaryResourceValue;
        OutProduction = SecondaryResourceValue;
        break;
    case ETileType::Forest:
        OutProduction = PrimaryResourceValue;
        OutFood = SecondaryResourceValue;
        break;
    case ETileType::Mountain:
        OutScience = PrimaryResourceValue;
        OutProduction = SecondaryResourceValue;
        break;
    case ETileType::Water:
        OutGold = PrimaryResourceValue;
        // �Ĺ� ��� ���� �� �ķ� ���� ����
        break;
    }
}

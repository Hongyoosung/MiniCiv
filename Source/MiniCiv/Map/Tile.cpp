// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"

void ATile::InitializeResources()
{
    switch (TileType)
    {
    case ETileType::Plains:
        PrimaryResourceValue = FMath::RandRange(3, 5);  // 식량
        SecondaryResourceValue = FMath::RandRange(0, 1);  // 생산력
        break;
    case ETileType::Forest:
        PrimaryResourceValue = FMath::RandRange(3, 5);  // 생산력
        SecondaryResourceValue = FMath::RandRange(1, 2);  // 식량
        break;
    case ETileType::Mountain:
        PrimaryResourceValue = FMath::RandRange(3, 5);  // 과학
        SecondaryResourceValue = FMath::RandRange(0, 1);  // 생산력
        break;
    case ETileType::Water:
        PrimaryResourceValue = FMath::RandRange(2, 4);  // 금
        SecondaryResourceValue = 0;  // 초기에는 추가 자원 없음
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
        // 후반 기술 연구 후 식량 생산 가능
        break;
    }
}

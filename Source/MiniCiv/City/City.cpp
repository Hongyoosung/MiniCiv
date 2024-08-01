// Fill out your copyright notice in the Description page of Project Settings.


#include "City.h"
#include "MiniCiv/Map/Tile.h"

ACity::ACity()
	: Population(1), StoredFood(0), StoredProduction(0), StoredScience(0), StoredGold(0)
{
}

void ACity::CollectResources()
{
    for (ATile* Tile : WorkedTiles)
    {
        int32 Food, Production, Science, Gold;
        Tile->GetResourceProduction(Food, Production, Science, Gold);

        StoredFood += Food;
        StoredProduction += Production;
        StoredScience += Science;
        StoredGold += Gold;
    }
}

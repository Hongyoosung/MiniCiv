// Fill out your copyright notice in the Description page of Project Settings.


#include "Civilization.h"
#include "MiniCiv/City/City.h"

void ACivilization::CollectResourcesFromCities()
{
    for (ACity* City : Cities)
    {
        City->CollectResources();

        Food += City->StoredFood;
        Production += City->StoredProduction;
        Science += City->StoredScience;
        Gold += City->StoredGold;

        // 도시의 저장소를 비웁니다
        City->StoredFood = 0;
        City->StoredProduction = 0;
        City->StoredScience = 0;
        City->StoredGold = 0;
    }
}

void ACivilization::EndTurn()
{
	for (ACity* City : Cities)
	{
		City->CollectResources();
	}

	// 연구, 건설 등의 진행 처리
}

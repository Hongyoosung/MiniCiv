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

        // ������ ����Ҹ� ���ϴ�
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

	// ����, �Ǽ� ���� ���� ó��
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "RuleBasedAIAdapter.h"

RuleBasedAIAdapter::RuleBasedAIAdapter(ARuleBasedAIController* InController)
{
	Controller = InController;
}

void RuleBasedAIAdapter::MakeTurn(ACivilization* Civilization)
{

}

FString RuleBasedAIAdapter::GetCurrentStrategy() const
{

	return FString();
}

void RuleBasedAIAdapter::GetPerformanceMetrics(int32& OutTurnsPlayed, int32& OutCitiesBuilt, int32& OutUnitsProduced) const
{

}

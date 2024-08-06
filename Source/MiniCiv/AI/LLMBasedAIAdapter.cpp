// Fill out your copyright notice in the Description page of Project Settings.


#include "LLMBasedAIAdapter.h"

LLMBasedAIAdapter::LLMBasedAIAdapter(ALLMBasedAIController* InController)
{
	Controller = InController;
}

void LLMBasedAIAdapter::MakeTurn(ACivilization* Civilization)
{

}

FString LLMBasedAIAdapter::GetCurrentStrategy() const
{
	return FString();
}

void LLMBasedAIAdapter::GetPerformanceMetrics(int32& OutTurnsPlayed, int32& OutCitiesBuilt, int32& OutUnitsProduced) const
{

}

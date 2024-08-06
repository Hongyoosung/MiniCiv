// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MiniCiv/AI/AI_Adapter.h"
#include "LLMBasedAIController.h"

/**
 * 
 */
class MINICIV_API LLMBasedAIAdapter : public AI_Adapter
{
public:
	LLMBasedAIAdapter(ALLMBasedAIController* InController);

    virtual void MakeTurn(ACivilization* Civilization) override;
    virtual FString GetCurrentStrategy() const override;
    virtual void GetPerformanceMetrics(int32& OutTurnsPlayed, int32& OutCitiesBuilt, int32& OutUnitsProduced) const override;

private:
    ALLMBasedAIController* Controller;
};

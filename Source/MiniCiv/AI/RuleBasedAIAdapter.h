// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MiniCiv/AI/AI_Adapter.h"
#include "RuleBasedAIController.h"

/**
 * 
 */
class MINICIV_API RuleBasedAIAdapter : public AI_Adapter
{
public:
    RuleBasedAIAdapter(ARuleBasedAIController* InController);

    virtual void MakeTurn(ACivilization* Civilization) override;
    virtual FString GetCurrentStrategy() const override;
    virtual void GetPerformanceMetrics(int32& OutTurnsPlayed, int32& OutCitiesBuilt, int32& OutUnitsProduced) const override;

private:
    ARuleBasedAIController* Controller;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MiniCiv/Unit/Civilization.h"

/**
 * 
 */
class MINICIV_API AI_Adapter
{
public:
	virtual void MakeTurn(ACivilization* Civilization) = 0;
	virtual FString GetCurrentStrategy() const = 0;
	virtual void GetPerformanceMetrics(int32& OutTurnsPlayed, int32& OutCitiesBuilt, int32& OutUnitsProduced) const = 0;
};

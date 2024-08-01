// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "MiniCiv/City/City.h"
#include "Civilization.generated.h"

/**
 * 
 */
UCLASS()
class MINICIV_API ACivilization : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CollectResourcesFromCities();
	void EndTurn();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Civilization")
	TArray<ACity*> Cities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Civilization")
	int32 Food;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Civilization")
	int32 Production;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Civilization")
	int32 Science;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Civilization")
	int32 Gold;
};

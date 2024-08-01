// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniCiv/Map/Tile.h"
#include "City.generated.h"

UCLASS()
class MINICIV_API ACity : public AActor
{
	GENERATED_BODY()
	
public:	
    ACity();

    UFUNCTION(BlueprintCallable)
    void CollectResources();

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Population;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<ATile*> WorkedTiles;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StoredFood;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StoredProduction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StoredScience;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StoredGold;
};

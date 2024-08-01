// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UENUM()
enum class ETileType : uint8
{
	Plains,
	Forest,
	Mountain,
	Water,
};


UCLASS()
class MINICIV_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ETileType TileType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 FoodProduction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ProductionValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ScienceValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 GoldValue;
};

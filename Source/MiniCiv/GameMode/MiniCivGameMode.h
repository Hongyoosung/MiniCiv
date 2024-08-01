// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MiniCiv/Map/Tile.h"
#include "MiniCivGameMode.generated.h"


UCLASS()
class MINICIV_API AMiniCivGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AMiniCivGameMode();
	virtual void StartPlay() override;


public:
	TArray<ATile*> Tiles;
};

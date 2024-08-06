// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MiniCiv/Map/Tile.h"
#include "MiniCiv/AI/AI_Adapter.h"
#include "MiniCivGameMode.generated.h"


UCLASS()
class MINICIV_API AMiniCivGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMiniCivGameMode();

	virtual void StartPlay() override;
	void SimulateGame(int32 TurnLimit);

private:
	void CreateGameMap();
	bool CheckVictryCondition();

public:
	UPROPERTY()
	TArray<ATile*> Tiles;

private:
	TMap<ACivilization*, TUniquePtr<AI_Adapter>> CivilizationsAndAIs;
};

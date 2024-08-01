// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniCivGameMode.h"


AMiniCivGameMode::AMiniCivGameMode()
{

}

void AMiniCivGameMode::StartPlay()
{
	Super::StartPlay();
	
	// Create 10x10 grid of tiles
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			FVector Location = FVector(x * 100, y * 100, 0);
			ATile* NewTile = GetWorld()->SpawnActor<ATile>(ATile::StaticClass(), Location, FRotator::ZeroRotator);

			// 타일 타입과 자원을 무작위로 설정
			NewTile->TileType = static_cast<ETileType>(FMath::RandRange(0, 3));
			NewTile->InitializeResources();

			Tiles.Add(NewTile);
		}
	}
}

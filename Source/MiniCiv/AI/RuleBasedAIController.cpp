// Fill out your copyright notice in the Description page of Project Settings.


#include "RuleBasedAIController.h"

ARuleBasedAIController::ARuleBasedAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}

void ARuleBasedAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (BehaviorTree)
	{
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}
}


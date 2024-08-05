// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "RuleBasedAIController.generated.h"

/**
 * 
 */
UCLASS()
class MINICIV_API ARuleBasedAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ARuleBasedAIController();

	virtual void OnPossess(APawn* InPawn) override;

	template<typename T>
	T GetBlackboardValues(const FName& KeyName, const T& Value) const;

private:
	UPROPERTY(transient)
	UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
};


template<typename T>
inline T ARuleBasedAIController::GetBlackboardValues(const FName& KeyName, const T& Value) const
{

	GetBlackboardComponent()->GetValueAs<T>(KeyName, Value);
	return Value;

}

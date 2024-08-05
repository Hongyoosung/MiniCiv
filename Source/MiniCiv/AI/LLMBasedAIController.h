// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Http.h"
#include "Json.h"
#include "LLMBasedAIController.generated.h"

/**
 * 
 */

#define OPENAI_API_KEY ""

UCLASS()
class MINICIV_API ALLMBasedAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ALLMBasedAIController();

	void SendRequest(const FString& InMessage);
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

private:
    UPROPERTY(EditAnywhere, Category = "ChatGPT")
    FString ApiEndpoint;

    UPROPERTY(EditAnywhere, Category = "ChatGPT")
    FString ApiKey;

    TSharedPtr<IHttpRequest> HttpRequest;
};

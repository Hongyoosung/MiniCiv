// Fill out your copyright notice in the Description page of Project Settings.


#include "LLMBasedAIController.h"

ALLMBasedAIController::ALLMBasedAIController()
{
	ApiEndpoint = "https://api.openai.com/v1/chat/completions";
	ApiKey = OPENAI_API_KEY;
}

void ALLMBasedAIController::MakeDecision(const FString& GameState)
{
	FString Prompt = "You are an AI player in a turn-based strategy game. \n"
		"You must decide your next action based on the given game state.\n " 
		"You may choose only one action each turn. Respond only in one of the following formats:\n\n" 
		"1. Build a city\n" 
		"2. Research\n" 
		"3. Produce a unit\n" 
		"4. Move and attack a unit\n\n" 
		"Current Game State:\n" + GameState + "\n\nDecide your next action:";
}

void ALLMBasedAIController::SendRequest(const FString& InMessage)
{
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &ALLMBasedAIController::OnResponseReceived);
	HttpRequest->SetURL(ApiEndpoint);
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetHeader("Authorization", "Bearer " + ApiKey);
	HttpRequest->SetVerb("POST");
	HttpRequest->SetContentAsString("{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"system\", \"content\": \"You are a helpful assistant.\"}, {\"role\": \"user\", \"content\": \"" + InMessage + "\"}]}");
	HttpRequest->ProcessRequest();
}

void ALLMBasedAIController::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (!bWasSuccessful)
    {
        UE_LOG(LogTemp, Error, TEXT("Request failed"));
        return;
    }

    FString ResponseString = Response->GetContentAsString();
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseString);

    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        TArray<TSharedPtr<FJsonValue>> Choices = JsonObject->GetArrayField("choices");
        TSharedPtr<FJsonObject> Choice = Choices[0]->AsObject();
        TSharedPtr<FJsonObject> Message = Choice->GetObjectField("message");
        FString ActionString = Message->GetStringField("content");
        UE_LOG(LogTemp, Warning, TEXT("LLM Action: %s"), *ActionString);

        ParseAndExecuteAction(ActionString);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON response"));
    }
}

void ALLMBasedAIController::ParseAndExecuteAction(const FString& ActionString)
{
    TArray<FString> Parts;
    ActionString.ParseIntoArray(Parts, TEXT(","), true);

    if (Parts.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid action string"));
        return;
    }

    FString ActionType = Parts[0];

    if (ActionType == "BUILD_CITY")
    {
        if (Parts.Num() != 3)
        {
            UE_LOG(LogTemp, Error, TEXT("Invalid BUILD_CITY format"));
            return;
        }
        int32 X = FCString::Atoi(*Parts[1]);
        int32 Y = FCString::Atoi(*Parts[2]);
        // 도시 건설 로직 실행
        UE_LOG(LogTemp, Warning, TEXT("Building city at (%d, %d)"), X, Y);
    }
    else if (ActionType == "RESEARCH")
    {
        if (Parts.Num() != 2)
        {
            UE_LOG(LogTemp, Error, TEXT("Invalid RESEARCH format"));
            return;
        }
        FString TechName = Parts[1];
        // 연구 로직 실행
        UE_LOG(LogTemp, Warning, TEXT("Researching technology: %s"), *TechName);
    }
    else if (ActionType == "PRODUCE_UNIT")
    {
        if (Parts.Num() != 3)
        {
            UE_LOG(LogTemp, Error, TEXT("Invalid PRODUCE_UNIT format"));
            return;
        }
        FString CityName = Parts[1];
        FString UnitType = Parts[2];
        // 유닛 생산 로직 실행
        UE_LOG(LogTemp, Warning, TEXT("Producing %s unit in %s"), *UnitType, *CityName);
    }
    else if (ActionType == "MOVE_UNIT")
    {
        if (Parts.Num() != 4)
        {
            UE_LOG(LogTemp, Error, TEXT("Invalid MOVE_UNIT format"));
            return;
        }
        FString UnitID = Parts[1];
        int32 TargetX = FCString::Atoi(*Parts[2]);
        int32 TargetY = FCString::Atoi(*Parts[3]);
        // 유닛 이동 및 공격 로직 실행
        UE_LOG(LogTemp, Warning, TEXT("Moving unit %s to (%d, %d)"), *UnitID, TargetX, TargetY);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Unknown action type: %s"), *ActionType);
    }
}

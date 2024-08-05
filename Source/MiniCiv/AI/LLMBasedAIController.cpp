// Fill out your copyright notice in the Description page of Project Settings.


#include "LLMBasedAIController.h"

ALLMBasedAIController::ALLMBasedAIController()
{
	ApiEndpoint = "https://api.openai.com/v1/chat/completions";
	ApiKey = OPENAI_API_KEY;
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
		FString Text = Message->GetStringField("content");
		UE_LOG(LogTemp, Warning, TEXT("Response: %s"), *Text);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON response"));
	}
}

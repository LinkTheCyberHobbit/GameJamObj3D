// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "SpawnerWreckship.generated.h"

class AWreckshipItem;

UCLASS()
class GAMEJAMPROJECT_API ASpawnerWreckship : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Components")
	TObjectPtr<UBoxComponent> spawnBox = nullptr;

#pragma region Settings
	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Settings")
	float minDelay = 0.3f;
	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Settings")
	float maxDelay = 2;
	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Settings")
	int currentSpawned = 0;
	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Settings")
	int maxSpawned = 5;
#pragma endregion Settings

	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Spawn")
	TSubclassOf<AActor> itemToSpawn = nullptr;
	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Spawn")
	TArray<TObjectPtr<AActor>> spawnedItems;
	UPROPERTY(EditAnywhere, Category = "SpawnerWreckShip|Spawn")
	float spawnTimer = 2;

public:	
	// Sets default values for this actor's properties
	ASpawnerWreckship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnItem();
	void RemoveItem(TObjectPtr<AWreckshipItem> _item);
	FVector GetRandomPointInBox();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

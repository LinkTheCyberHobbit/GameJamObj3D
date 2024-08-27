// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerWreckship.h"

// Sets default values
ASpawnerWreckship::ASpawnerWreckship()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawnBox = CreateDefaultSubobject<UBoxComponent>("SpawnBox");
	spawnBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpawnerWreckship::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnerWreckship::SpawnItem()
{
    if (spawnedItems.Num() < maxSpawned)
    {
        FVector _spawnLocation = GetRandomPointInBox();
        FRotator _spawnRotation = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);

        TObjectPtr<AActor> _spawnedItem = GetWorld()->SpawnActor<AActor>(itemToSpawn, _spawnLocation, _spawnRotation);

        if (_spawnedItem)
        {
            spawnedItems.Add(_spawnedItem);
            TObjectPtr<AWreckshipItem> _wreckshipItem = Cast<AWreckshipItem>(_spawnedItem);
            if (_wreckshipItem)
            {
                
            }
        }

        // Délai avant la prochaine génération
        float _delayDuration = FMath::RandRange(minDelay, maxDelay);
    }
}

void ASpawnerWreckship::RemoveItem(TObjectPtr<AWreckshipItem> _item)
{
    //enlever ici ou dans l'item du tableau
}

FVector ASpawnerWreckship::GetRandomPointInBox()
{
    //Randomize
    return FVector();
}

// Called every frame
void ASpawnerWreckship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}


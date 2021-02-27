// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTest.h"
#include "MyActorComponent.h"
DEFINE_LOG_CATEGORY(LogMyActorLifeCycle);

// Sets default values
AMyTest::AMyTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UMyActorComponent* MyComp = CreateDefaultSubobject<UMyActorComponent>(TEXT("MyTestComponent"));
	AddInstanceComponent(MyComp);
}

// Called when the game starts or when spawned
void AMyTest::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::BeginPlay"));
}

// Called every frame
void AMyTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTest::PostLoad()
{
	Super::PostLoad();
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::PostLoad()"));
}

void AMyTest::PostActorCreated()
{
	Super::PostActorCreated();

	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::PostActorCreated()"));
}

void AMyTest::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::PostDuplicate(bool bDuplicateForPIE): %d "), bDuplicateForPIE);
}

void AMyTest::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::PreInitializeComponents"));
}

void AMyTest::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::PostInitializeComponents"));
}

void AMyTest::Destroyed()
{
	Super::Destroyed(); // Call EndPlay
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::Destroyed"));

}

void AMyTest::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::EndPlay(%d)"), static_cast<int>(EndPlayReason));

}
void AMyTest::BeginDestroy()
{
	Super::BeginDestroy();
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::BeginDestroy"));

}
bool AMyTest::IsReadyForFinishDestroy()
{
	Super::IsReadyForFinishDestroy();
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::IsReadyForFinishDestroy"));
	return true;
}
void AMyTest::FinishDestroy()
{
	Super::FinishDestroy();
	UE_LOG(LogMyActorLifeCycle, Warning, TEXT("Call------------------>>> AMyTest::FinishDestroy"));
}

void AMyTest::MyNative_Implementation()
{

}



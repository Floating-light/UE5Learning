// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayFramework/MyPlayerController.h"
#include "Net/UnrealNetwork.h"
//#include "MyProjectCharacter.h"
DEFINE_LOG_CATEGORY_STATIC(LogMyPlayerController, Log, All);

AMyPlayerController::AMyPlayerController()
{
	TestStruct.StringReplicated2 = "Rep_ChangedInConstructor";
	TestStruct.StringNoReplicated2 = "NotRep_ChangedInConstructor";
}


void AMyPlayerController::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);

	//AMyProjectCharacter* MyCharacter = Cast<AMyProjectCharacter>(P);
	//if (MyCharacter)
	//{
	//	MyCharacter->GetAbilitySystemComponent()->InitAbilityActorInfo(MyCharacter, MyCharacter);
	//}
}

void AMyPlayerController::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMyPlayerController, TestStruct);
 }


void AMyPlayerController::Rep_TestStruct()
{
	UE_LOG(LogMyPlayerController, Display, TEXT("Property TestStruct: "));

}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InputComponent->BindKey(EKeys::Q, EInputEvent::IE_Pressed, this, &AMyPlayerController::Pressed_Q);
	InputComponent->BindKey(EKeys::W, EInputEvent::IE_Pressed, this, &AMyPlayerController::Pressed_W);
}

void AMyPlayerController::Pressed_Q()
{
	UE_LOG(LogMyPlayerController, Display, TEXT("Property TestStruct: "));
	UE_LOG(LogMyPlayerController, Display, TEXT("	StringReplicated : %s"), *TestStruct.StringReplicated);
	UE_LOG(LogMyPlayerController, Display, TEXT("	StringReplicated2 : %s"), *TestStruct.StringReplicated2);
	UE_LOG(LogMyPlayerController, Display, TEXT("	StringNoReplicated : %s"), *TestStruct.StringNoReplicated);
	UE_LOG(LogMyPlayerController, Display, TEXT("	StringNoReplicated2 : %s"), *TestStruct.StringNoReplicated2);
}

void AMyPlayerController::ServerPrint_Implementation()
{
	Pressed_Q();
}


void AMyPlayerController::Pressed_W_Implementation()
{
	TestStruct.StringReplicated2 = "Change_InServer";
	TestStruct.StringNoReplicated2 = "Change_InServer";
}


void AMyPlayerController::OnActorChannelOpen(class FInBunch& InBunch, class UNetConnection* Connection)
{
	Super::OnActorChannelOpen(InBunch, Connection);
	UE_LOG(LogMyPlayerController, Display, TEXT("----------->> %s"), TEXT(__FUNCTION__));
}
void AMyPlayerController::OnSerializeNewActor(class FOutBunch& OutBunch)
{
	Super::OnSerializeNewActor(OutBunch);
	UE_LOG(LogMyPlayerController, Display, TEXT("----------->> %s"), TEXT(__FUNCTION__));
}
void AMyPlayerController::PostNetReceiveRole()
{
	Super::PostNetReceive();
	UE_LOG(LogMyPlayerController, Display, TEXT("----------->> %s"), TEXT(__FUNCTION__));
}

void AMyPlayerController::PostNetInit()
{
	Super::PostNetInit();
	UE_LOG(LogMyPlayerController, Display, TEXT("----------->> %s"), TEXT(__FUNCTION__));
	Pressed_Q();
}
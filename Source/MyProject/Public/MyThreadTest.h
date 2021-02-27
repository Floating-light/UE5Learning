#pragma once
#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "MyProject/MyProject.h"
//C:\Myfloder\UnrealProject\MyProject\Source\MyProject\MyProject.h

// 放到FRunnableThread中执行.
//C:\Program Files\Epic Games\UE_4.25\Engine\Source\Runtime\Core\Public\HAL\RunnableThread.h
// https://blog.csdn.net/SUKHOI27SMK/article/details/82997825

class MyThreadTest : public FRunnable
{
public:
	MyThreadTest() {} 
	virtual bool Init() override
	{
		Id = FString::Printf(TEXT("Instance%d"), ++Count);
		return true;
	}

	virtual uint32 Run() override
	{
		for (int i = 0; i < 100; ++i)
		{
			UE_LOG(LogTestGame, Warning, TEXT("%s : -------------->>> %d"), *Id, i);
		}
		GEngine->AddOnScreenDebugMessage();
		return 0;
	}

	virtual void Stop() override 
	{

	}

	virtual void Exit() override 
	{

	}

private:
	FString Id;
	static int32 Count;
};


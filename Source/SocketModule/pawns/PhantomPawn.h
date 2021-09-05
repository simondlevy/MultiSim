/*
* Class declaration for DJI Phantom pawn class using UDP sockets
*
* Copyright (C) 2019 Simon D. Levy
*
* MIT License
*/

#pragma once

#include "../../MainModule/vehicles/Phantom.hpp"

#include "../FlightManager.hpp"

#include <CoreMinimal.h>
#include <GameFramework/Pawn.h>

#include "PhantomPawn.generated.h"

UCLASS(Config=Game)
class APhantomPawn : public APawn {

    private:

        GENERATED_BODY()

        // Helper class
        Phantom _phantom;


        FSocketFlightManager * _flightManager = NULL;

    protected:

        // AActor overrides

        virtual void BeginPlay() override;

        virtual void Tick(float DeltaSeconds) override;

        virtual void PostInitializeComponents() override;

        virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

        // virtual void NotifyHit(...) override

    public:	

        APhantomPawn();

}; // APhantomPawn

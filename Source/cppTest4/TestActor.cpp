// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "StaticMeshResources.h"
#include "IPFMExporter.h"
#include "IPFMExporterBlueprintAPI.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	UActorComponent* comp = GetComponentByClass(UStaticMeshComponent::StaticClass());
	
	TArray<UStaticMeshComponent*> Components;
	GetComponents<UStaticMeshComponent>(Components);

	USceneComponent* OriginComp = (sceneComp) ? sceneComp : Components[0]->GetAttachParent();
	
	const FTransform& OriginToWorldTransform = (OriginComp ? OriginComp->GetComponentTransform() : FTransform::Identity);
	
	FTransform MeshToWorldTransform = Components[0]->GetComponentTransform();

	FMatrix WorldToOrigin = OriginToWorldTransform.ToInverseMatrixWithScale();
	FMatrix MeshToWorld   = MeshToWorldTransform.ToMatrixWithScale();

	FMatrix MeshToOrigin = MeshToWorld * WorldToOrigin;

	UStaticMesh* StaticMesh = Components[0]->GetStaticMesh();
	

	IPFMExporter::Get().ExportPFM(&StaticMesh->GetLODForExport(0), MeshToOrigin, 300, 200, "Stagodalo");
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


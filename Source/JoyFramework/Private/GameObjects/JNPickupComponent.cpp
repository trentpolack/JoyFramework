UJNPickupComponent::UJNPickupComponent( )
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UJNPickupComponent::BeginPlay( )
{
	Super::BeginPlay( );

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic( this, &UJNPickupComponent::OnSphereBeginOverlap );
}

void UJNPickupComponent::OnSphereBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult )
{
	// Checking if it is a First Person Character overlapping
	AJNCharacter* Character = Cast< AJNCharacter >( OtherActor );
	if( Character != nullptr )
	{
		// Notify that the actor is being picked up
		OnPickup.Broadcast( Character );

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll( this );
	}
}

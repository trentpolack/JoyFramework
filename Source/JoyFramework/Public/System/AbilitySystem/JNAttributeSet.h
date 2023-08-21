#pragma once

#include "AttributeSet.h"

#include "JNAttributeSet.generated.h"

/**
 * This macro defines a set of helper functions for accessing and initializing attributes.
 *
 * The following example of the macro:
 *		ATTRIBUTE_ACCESSORS(ULyraHealthSet, Health)
 * will create the following functions:
 *		static FGameplayAttribute GetHealthAttribute();
 *		float GetHealth() const;
 *		void SetHealth(float NewVal);
 *		void InitHealth(float NewVal);
 */
#define ATTRIBUTE_ACCESSORS( ClassName, PropertyName )				\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER( ClassName, PropertyName )	\
	GAMEPLAYATTRIBUTE_VALUE_GETTER( PropertyName )					\
	GAMEPLAYATTRIBUTE_VALUE_SETTER( PropertyName )					\
	GAMEPLAYATTRIBUTE_VALUE_INITTER( PropertyName )

UCLASS( )
class UJNAttributeSet : public UAttributeSet
{
	GENERATED_BODY( )

public:
	UJNAttributeSet( const FObjectInitializer& ObjectInitializer );

};
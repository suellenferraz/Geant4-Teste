#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction() : G4VUserDetectorConstruction()
{ }

MyDetectorConstruction::~MyDetectorConstruction()
{ }

G4VPhysicalVolume* MyDetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

    G4Box* solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);

    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, world_mat, "logicWorld");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0, true);

    return physWorld;
}


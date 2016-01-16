/**
 * Fields of colour that blend to white
 */

// Number of points in the particle system

void colourFieldsSetup() {
  byte i;

  gFrameDelay = 10;

  for(i=0; i<NUM_POINTS; i++) {
    // Position and colour randomly
    initParticle(i, random16(LEDS_PER_HOOP * 16), CHSV(random8(), 255, 255));

    // Set some initial movement/force
    setParticleMovement(i, (random8()-127)*4, (random8()-127)*16);

    // Constrain each particle to live within the first hoop
    setParticleConstraints(i, 0, LEDS_PER_HOOP-1);
  }
}

void colourFields() {
  moveParticles();

  fadeToBlackBy(leds, NUM_LEDS, 30);
  drawParticles();
  //blendBetweenParticles();
}

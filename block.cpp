// Basic block rendering code.
float l_length = 1.0 f; 
float l_height = 1.0 f;
float l_width = 1.0 f;

// The position of the block in the world.
Vector3d blockPosition( 0.0 f, 0.0 f, 0.0 f);

pRenderer->PushMatrix(); // Save the current world matrix.
pRenderer-> TranslateWorldMatrix( blockPosition.x, blockPosition.y, blockPosition.z);
// Render the block using a simple cube model.
pRenderer->SetRenderMode( RM_SOLID );
pRenderer->EnableImmediateMode( IM_QUADS );
pRenderer-> ImmediateColor( 1.0 f, 1.0 f, 1.0 f, 1.0 f);

pRenderer-> ImmediateNormal( 0.0 f, 0.0 f, -1.0 f); 
pRenderer-> ImmediateVertex(l_length, -l_height,-l_width); // Front face
pRenderer-> ImmediateVertex(-l_length, -l_height,-l_width);
pRenderer->ImmediateVertex(-l_length, l_height, -l_width);
pRenderer->ImmediateVertex(l_length, l_height, -l_width);

// Repeat for the other faces of the cube, changing the normal and vertex positions accordingly.
pRenderer-> ImmediateNormal( 0.0 f, 0.0 f, 1.0 f);
pRenderer->ImmediateVertex(-l_length, -l_height, l_width);
pRenderer->ImmediateVertex(l_length, -l_height, l_width);
pRenderer->ImmediateVertex(l_length, l_height, l_width);
pRenderer->ImmediateVertex(-l_length, l_height, l_width);

// Left face
pRenderer->ImmediateNormal(1.0 f, 0.0 f, 0.0 f);
pRenderer->ImmediateVertex(l_length, -l_height, l_width);
pRenderer->ImmediateVertex(l_length, -l_height, -l_width);
pRenderer->ImmediateVertex(l_length, l_height, -l_width);
pRenderer->ImmediateVertex(l_length, l_height, l_width);

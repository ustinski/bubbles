OBJECTS_LOCAL=app.o texture.o vector.o bubble.o background.o bubblecontainer.o program.o Box2D_Common_b2Draw.o Box2D_Common_b2BlockAllocator.o Box2D_Common_b2Timer.o Box2D_Common_b2Math.o Box2D_Common_b2Settings.o Box2D_Common_b2StackAllocator.o Box2D_Dynamics_b2WorldCallbacks.o Box2D_Dynamics_b2World.o Box2D_Dynamics_b2ContactManager.o Box2D_Dynamics_b2Fixture.o Box2D_Dynamics_b2Island.o Box2D_Dynamics_b2Body.o Box2D_Dynamics_Contacts_b2ChainAndCircleContact.o Box2D_Dynamics_Contacts_b2EdgeAndCircleContact.o Box2D_Dynamics_Contacts_b2Contact.o Box2D_Dynamics_Contacts_b2PolygonContact.o Box2D_Dynamics_Contacts_b2ContactSolver.o Box2D_Dynamics_Contacts_b2CircleContact.o Box2D_Dynamics_Contacts_b2ChainAndPolygonContact.o Box2D_Dynamics_Contacts_b2PolygonAndCircleContact.o Box2D_Dynamics_Contacts_b2EdgeAndPolygonContact.o Box2D_Dynamics_Joints_b2Joint.o Box2D_Dynamics_Joints_b2DistanceJoint.o Box2D_Dynamics_Joints_b2WeldJoint.o Box2D_Dynamics_Joints_b2MouseJoint.o Box2D_Dynamics_Joints_b2PulleyJoint.o Box2D_Dynamics_Joints_b2MotorJoint.o Box2D_Dynamics_Joints_b2RevoluteJoint.o Box2D_Dynamics_Joints_b2WheelJoint.o Box2D_Dynamics_Joints_b2FrictionJoint.o Box2D_Dynamics_Joints_b2PrismaticJoint.o Box2D_Dynamics_Joints_b2RopeJoint.o Box2D_Dynamics_Joints_b2GearJoint.o Box2D_Collision_b2TimeOfImpact.o Box2D_Collision_b2DynamicTree.o Box2D_Collision_b2BroadPhase.o Box2D_Collision_b2CollideEdge.o Box2D_Collision_b2Collision.o Box2D_Collision_b2Distance.o Box2D_Collision_b2CollideCircle.o Box2D_Collision_b2CollidePolygon.o Box2D_Collision_Shapes_b2PolygonShape.o Box2D_Collision_Shapes_b2CircleShape.o Box2D_Collision_Shapes_b2ChainShape.o Box2D_Collision_Shapes_b2EdgeShape.o Box2D_Rope_b2Rope.o 
app.o : $(SRC_DIR)/app.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/app.cpp -o app.o 
texture.o : $(SRC_DIR)/texture.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/texture.cpp -o texture.o 
vector.o : $(SRC_DIR)/vector.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/vector.cpp -o vector.o 
bubble.o : $(SRC_DIR)/bubble.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/bubble.cpp -o bubble.o 
background.o : $(SRC_DIR)/background.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/background.cpp -o background.o 
bubblecontainer.o : $(SRC_DIR)/bubblecontainer.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/bubblecontainer.cpp -o bubblecontainer.o 
program.o : $(SRC_DIR)/program.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/program.cpp -o program.o 
Box2D_Common_b2Draw.o : $(SRC_DIR)/Box2D/Common/b2Draw.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Common/b2Draw.cpp -o Box2D_Common_b2Draw.o 
Box2D_Common_b2BlockAllocator.o : $(SRC_DIR)/Box2D/Common/b2BlockAllocator.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Common/b2BlockAllocator.cpp -o Box2D_Common_b2BlockAllocator.o 
Box2D_Common_b2Timer.o : $(SRC_DIR)/Box2D/Common/b2Timer.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Common/b2Timer.cpp -o Box2D_Common_b2Timer.o 
Box2D_Common_b2Math.o : $(SRC_DIR)/Box2D/Common/b2Math.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Common/b2Math.cpp -o Box2D_Common_b2Math.o 
Box2D_Common_b2Settings.o : $(SRC_DIR)/Box2D/Common/b2Settings.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Common/b2Settings.cpp -o Box2D_Common_b2Settings.o 
Box2D_Common_b2StackAllocator.o : $(SRC_DIR)/Box2D/Common/b2StackAllocator.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Common/b2StackAllocator.cpp -o Box2D_Common_b2StackAllocator.o 
Box2D_Dynamics_b2WorldCallbacks.o : $(SRC_DIR)/Box2D/Dynamics/b2WorldCallbacks.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/b2WorldCallbacks.cpp -o Box2D_Dynamics_b2WorldCallbacks.o 
Box2D_Dynamics_b2World.o : $(SRC_DIR)/Box2D/Dynamics/b2World.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/b2World.cpp -o Box2D_Dynamics_b2World.o 
Box2D_Dynamics_b2ContactManager.o : $(SRC_DIR)/Box2D/Dynamics/b2ContactManager.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/b2ContactManager.cpp -o Box2D_Dynamics_b2ContactManager.o 
Box2D_Dynamics_b2Fixture.o : $(SRC_DIR)/Box2D/Dynamics/b2Fixture.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/b2Fixture.cpp -o Box2D_Dynamics_b2Fixture.o 
Box2D_Dynamics_b2Island.o : $(SRC_DIR)/Box2D/Dynamics/b2Island.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/b2Island.cpp -o Box2D_Dynamics_b2Island.o 
Box2D_Dynamics_b2Body.o : $(SRC_DIR)/Box2D/Dynamics/b2Body.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/b2Body.cpp -o Box2D_Dynamics_b2Body.o 
Box2D_Dynamics_Contacts_b2ChainAndCircleContact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp -o Box2D_Dynamics_Contacts_b2ChainAndCircleContact.o 
Box2D_Dynamics_Contacts_b2EdgeAndCircleContact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp -o Box2D_Dynamics_Contacts_b2EdgeAndCircleContact.o 
Box2D_Dynamics_Contacts_b2Contact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2Contact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2Contact.cpp -o Box2D_Dynamics_Contacts_b2Contact.o 
Box2D_Dynamics_Contacts_b2PolygonContact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2PolygonContact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2PolygonContact.cpp -o Box2D_Dynamics_Contacts_b2PolygonContact.o 
Box2D_Dynamics_Contacts_b2ContactSolver.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ContactSolver.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ContactSolver.cpp -o Box2D_Dynamics_Contacts_b2ContactSolver.o 
Box2D_Dynamics_Contacts_b2CircleContact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2CircleContact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2CircleContact.cpp -o Box2D_Dynamics_Contacts_b2CircleContact.o 
Box2D_Dynamics_Contacts_b2ChainAndPolygonContact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp -o Box2D_Dynamics_Contacts_b2ChainAndPolygonContact.o 
Box2D_Dynamics_Contacts_b2PolygonAndCircleContact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp -o Box2D_Dynamics_Contacts_b2PolygonAndCircleContact.o 
Box2D_Dynamics_Contacts_b2EdgeAndPolygonContact.o : $(SRC_DIR)/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp -o Box2D_Dynamics_Contacts_b2EdgeAndPolygonContact.o 
Box2D_Dynamics_Joints_b2Joint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2Joint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2Joint.cpp -o Box2D_Dynamics_Joints_b2Joint.o 
Box2D_Dynamics_Joints_b2DistanceJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2DistanceJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2DistanceJoint.cpp -o Box2D_Dynamics_Joints_b2DistanceJoint.o 
Box2D_Dynamics_Joints_b2WeldJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2WeldJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2WeldJoint.cpp -o Box2D_Dynamics_Joints_b2WeldJoint.o 
Box2D_Dynamics_Joints_b2MouseJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2MouseJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2MouseJoint.cpp -o Box2D_Dynamics_Joints_b2MouseJoint.o 
Box2D_Dynamics_Joints_b2PulleyJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2PulleyJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2PulleyJoint.cpp -o Box2D_Dynamics_Joints_b2PulleyJoint.o 
Box2D_Dynamics_Joints_b2MotorJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2MotorJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2MotorJoint.cpp -o Box2D_Dynamics_Joints_b2MotorJoint.o 
Box2D_Dynamics_Joints_b2RevoluteJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp -o Box2D_Dynamics_Joints_b2RevoluteJoint.o 
Box2D_Dynamics_Joints_b2WheelJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2WheelJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2WheelJoint.cpp -o Box2D_Dynamics_Joints_b2WheelJoint.o 
Box2D_Dynamics_Joints_b2FrictionJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2FrictionJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2FrictionJoint.cpp -o Box2D_Dynamics_Joints_b2FrictionJoint.o 
Box2D_Dynamics_Joints_b2PrismaticJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp -o Box2D_Dynamics_Joints_b2PrismaticJoint.o 
Box2D_Dynamics_Joints_b2RopeJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2RopeJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2RopeJoint.cpp -o Box2D_Dynamics_Joints_b2RopeJoint.o 
Box2D_Dynamics_Joints_b2GearJoint.o : $(SRC_DIR)/Box2D/Dynamics/Joints/b2GearJoint.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Dynamics/Joints/b2GearJoint.cpp -o Box2D_Dynamics_Joints_b2GearJoint.o 
Box2D_Collision_b2TimeOfImpact.o : $(SRC_DIR)/Box2D/Collision/b2TimeOfImpact.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2TimeOfImpact.cpp -o Box2D_Collision_b2TimeOfImpact.o 
Box2D_Collision_b2DynamicTree.o : $(SRC_DIR)/Box2D/Collision/b2DynamicTree.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2DynamicTree.cpp -o Box2D_Collision_b2DynamicTree.o 
Box2D_Collision_b2BroadPhase.o : $(SRC_DIR)/Box2D/Collision/b2BroadPhase.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2BroadPhase.cpp -o Box2D_Collision_b2BroadPhase.o 
Box2D_Collision_b2CollideEdge.o : $(SRC_DIR)/Box2D/Collision/b2CollideEdge.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2CollideEdge.cpp -o Box2D_Collision_b2CollideEdge.o 
Box2D_Collision_b2Collision.o : $(SRC_DIR)/Box2D/Collision/b2Collision.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2Collision.cpp -o Box2D_Collision_b2Collision.o 
Box2D_Collision_b2Distance.o : $(SRC_DIR)/Box2D/Collision/b2Distance.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2Distance.cpp -o Box2D_Collision_b2Distance.o 
Box2D_Collision_b2CollideCircle.o : $(SRC_DIR)/Box2D/Collision/b2CollideCircle.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2CollideCircle.cpp -o Box2D_Collision_b2CollideCircle.o 
Box2D_Collision_b2CollidePolygon.o : $(SRC_DIR)/Box2D/Collision/b2CollidePolygon.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/b2CollidePolygon.cpp -o Box2D_Collision_b2CollidePolygon.o 
Box2D_Collision_Shapes_b2PolygonShape.o : $(SRC_DIR)/Box2D/Collision/Shapes/b2PolygonShape.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/Shapes/b2PolygonShape.cpp -o Box2D_Collision_Shapes_b2PolygonShape.o 
Box2D_Collision_Shapes_b2CircleShape.o : $(SRC_DIR)/Box2D/Collision/Shapes/b2CircleShape.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/Shapes/b2CircleShape.cpp -o Box2D_Collision_Shapes_b2CircleShape.o 
Box2D_Collision_Shapes_b2ChainShape.o : $(SRC_DIR)/Box2D/Collision/Shapes/b2ChainShape.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/Shapes/b2ChainShape.cpp -o Box2D_Collision_Shapes_b2ChainShape.o 
Box2D_Collision_Shapes_b2EdgeShape.o : $(SRC_DIR)/Box2D/Collision/Shapes/b2EdgeShape.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Collision/Shapes/b2EdgeShape.cpp -o Box2D_Collision_Shapes_b2EdgeShape.o 
Box2D_Rope_b2Rope.o : $(SRC_DIR)/Box2D/Rope/b2Rope.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/Box2D/Rope/b2Rope.cpp -o Box2D_Rope_b2Rope.o 
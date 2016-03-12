LOCAL_PATH := $(call my-dir)



SRC_DIR := ../../../src

include $(CLEAR_VARS)

LOCAL_MODULE    := app
LOCAL_CFLAGS    := -Wall -Wextra
LOCAL_SRC_FILES := hook.cpp jni.c $(SRC_DIR)/app.cpp $(SRC_DIR)/texture.cpp $(SRC_DIR)/vector.cpp $(SRC_DIR)/bubble.cpp $(SRC_DIR)/background.cpp $(SRC_DIR)/bubblecontainer.cpp $(SRC_DIR)/program.cpp $(SRC_DIR)/Box2D/Common/b2Draw.cpp $(SRC_DIR)/Box2D/Common/b2BlockAllocator.cpp $(SRC_DIR)/Box2D/Common/b2Timer.cpp $(SRC_DIR)/Box2D/Common/b2Math.cpp $(SRC_DIR)/Box2D/Common/b2Settings.cpp $(SRC_DIR)/Box2D/Common/b2StackAllocator.cpp $(SRC_DIR)/Box2D/Dynamics/b2WorldCallbacks.cpp $(SRC_DIR)/Box2D/Dynamics/b2World.cpp $(SRC_DIR)/Box2D/Dynamics/b2ContactManager.cpp $(SRC_DIR)/Box2D/Dynamics/b2Fixture.cpp $(SRC_DIR)/Box2D/Dynamics/b2Island.cpp $(SRC_DIR)/Box2D/Dynamics/b2Body.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2Contact.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2PolygonContact.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ContactSolver.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2CircleContact.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp $(SRC_DIR)/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2Joint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2DistanceJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2WeldJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2MouseJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2PulleyJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2MotorJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2WheelJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2FrictionJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2RopeJoint.cpp $(SRC_DIR)/Box2D/Dynamics/Joints/b2GearJoint.cpp $(SRC_DIR)/Box2D/Collision/b2TimeOfImpact.cpp $(SRC_DIR)/Box2D/Collision/b2DynamicTree.cpp $(SRC_DIR)/Box2D/Collision/b2BroadPhase.cpp $(SRC_DIR)/Box2D/Collision/b2CollideEdge.cpp $(SRC_DIR)/Box2D/Collision/b2Collision.cpp $(SRC_DIR)/Box2D/Collision/b2Distance.cpp $(SRC_DIR)/Box2D/Collision/b2CollideCircle.cpp $(SRC_DIR)/Box2D/Collision/b2CollidePolygon.cpp $(SRC_DIR)/Box2D/Collision/Shapes/b2PolygonShape.cpp $(SRC_DIR)/Box2D/Collision/Shapes/b2CircleShape.cpp $(SRC_DIR)/Box2D/Collision/Shapes/b2ChainShape.cpp $(SRC_DIR)/Box2D/Collision/Shapes/b2EdgeShape.cpp $(SRC_DIR)/Box2D/Rope/b2Rope.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(SRC_DIR)
LOCAL_C_INCLUDES := $(LOCAL_EXPORT_C_INCLUDES)

LOCAL_LDLIBS := -lGLESv2 -llog 

include $(BUILD_SHARED_LIBRARY)

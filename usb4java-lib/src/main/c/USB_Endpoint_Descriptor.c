/*
 * Copyright (C) 2011 Klaus Reimer (k@ailis.de)
 * See COPYING file for copying conditions
 */

/**
 * @name USB_Endpoint_Descriptor
 *
 * Native methods for the USB_Endpoint_Descriptor class.
 *
 * @author Klaus Reimer <k@ailis.de>
 */

#include <jni.h>
#include <usb.h>
#include "usb4java.h"


/**
 * Creates and returns a new USB endpoint descriptor wrapper object.
 *
 * @param env
 *            The JNI environment.
 * @param descriptor
 *            The USB endpoint descriptor.
 * @return The USB endpoint descriptor wrapper object.
 */

jobject wrap_usb_endpoint_descriptor(JNIEnv *env,
    struct usb_endpoint_descriptor *descriptor)
{
    if (!descriptor) return NULL;
    jclass cls = (*env)->FindClass(env, PACKAGE_DIR"/USB_Endpoint_Descriptor");
    if (cls == NULL) return NULL;
    jmethodID constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)V");
    if (constructor == NULL) return NULL;
    return (*env)->NewObject(env, cls, constructor, (long) descriptor);
}


/**
 * Creates and returns an array with USB endpoint descriptor wrapper objects.
 *
 * @param env
 *            The JNI environment
 * @param num_descriptors
 *            The number of descriptors
 * @param descriptors
 *            The descriptors to wrap.
 * @return The array with the USB endpoint descriptor wrappers.
 */

jobjectArray wrap_usb_endpoint_descriptors(JNIEnv *env, uint8_t num_descriptors,
    struct usb_endpoint_descriptor *descriptors)
{
    int i;

    jobjectArray array = (jobjectArray) (*env)->NewObjectArray(env,
        num_descriptors, (*env)->FindClass(env,
        PACKAGE_DIR"/USB_Endpoint_Descriptor"), NULL);
    for (i = 0; i < num_descriptors; i++)
        (*env)->SetObjectArrayElement(env, array, i,
            wrap_usb_endpoint_descriptor(env, &descriptors[i]));
    return array;
}


/**
 * Returns the wrapped USB endpoint descriptor object from the specified
 * wrapper object.
 *
 * @param env
 *            The JNI environment.
 * @param obj
 *            The USB endpoint descriptor wrapper object.
 * @return The USB endpoint descriptor object.
 */
  
struct usb_endpoint_descriptor *unwrap_usb_endpoint_descriptor(JNIEnv *env,
    jobject obj)
{
     jclass cls = (*env)->GetObjectClass(env, obj);
     jfieldID field = (*env)->GetFieldID(env, cls, "pointer", "J");
     return (struct usb_endpoint_descriptor *) ((*env)->GetLongField(env,
         obj, field));
}


/**
 * short bEndpointAddress()
 */

JNIEXPORT jshort JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, bEndpointAddress)
(
    JNIEnv *env, jobject this
)
{
    return (jshort) unwrap_usb_endpoint_descriptor(env, this)->bEndpointAddress;
}


/**
 * short bmAttributes()
 */

JNIEXPORT jshort JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, bmAttributes)
(
    JNIEnv *env, jobject this
)
{
    return (jshort) unwrap_usb_endpoint_descriptor(env, this)->bmAttributes;
}


/**
 * int wMaxPacketSize()
 */

JNIEXPORT jint JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, wMaxPacketSize)
(
    JNIEnv *env, jobject this
)
{
    return (jshort) unwrap_usb_endpoint_descriptor(env, this)->wMaxPacketSize;
}


/**
 * short bInterval()
 */

JNIEXPORT jshort JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, bInterval)
(
    JNIEnv *env, jobject this
)
{
    return (jshort) unwrap_usb_endpoint_descriptor(env, this)->bInterval;
}


/**
 * short bRefresh()
 */

JNIEXPORT jshort JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, bRefresh)
(
    JNIEnv *env, jobject this
)
{
    return (jshort) unwrap_usb_endpoint_descriptor(env, this)->bRefresh;
}


/**
 * short bSynchAddress()
 */

JNIEXPORT jshort JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, bSynchAddress)
(
    JNIEnv *env, jobject this
)
{
    return (jshort) unwrap_usb_endpoint_descriptor(env, this)->bSynchAddress;
}


/**
 * int extralen()
 */

JNIEXPORT jint JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, extralen)
(
    JNIEnv *env, jobject this
)
{
    return unwrap_usb_endpoint_descriptor(env, this)->extralen;
}


/**
 * byte[] extra()
 */

JNIEXPORT jbyteArray JNICALL METHOD_NAME(USB_1Endpoint_1Descriptor, extra)
(
    JNIEnv *env, jobject this
)
{
    struct usb_endpoint_descriptor *descriptor =
        unwrap_usb_endpoint_descriptor(env, this);
    jbyteArray array = (*env)->NewByteArray(env, descriptor->extralen);
    (*env)->SetByteArrayRegion(env, array, 0, descriptor->extralen,
        (const jbyte *) descriptor->extra);
    return array;
}

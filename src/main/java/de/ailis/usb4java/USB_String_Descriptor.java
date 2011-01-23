/*
 * Copyright (C) 2011 Klaus Reimer <k@ailis.de>
 * See LICENSE.txt for licensing information.
 */

package de.ailis.usb4java;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.CharBuffer;


/**
 * A string descriptor.
 *
 * @author Klaus Reimer (k@ailis.de)
 */

public final class USB_String_Descriptor extends USB_Descriptor_Header
{
    /**
     * Constructor.
     *
     * @param data
     *            The descriptor data.
     */

    public USB_String_Descriptor(final ByteBuffer data)
    {
        super(data);
    }


    /**
     * Returns the string data in UTF-16 encoding.
     *
     * @return The string data.
     */

    public final char[] wData()
    {
        this.data.position(2);
        final CharBuffer chars = this.data.order(ByteOrder.LITTLE_ENDIAN)
                .asCharBuffer();
        final char[] output = new char[chars.remaining()];
        chars.get(output);
        return output;
    }


    /**
     * @see java.lang.Object#toString()
     */

    @Override
    public final String toString()
    {
        return new String(wData());
    }
}
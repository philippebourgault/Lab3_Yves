//==========================================
// experimental files
// COMPILE WITH:
// gcc usb_exp.c -lusb-1.0
//==========================================

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

//=========================================================================
// This program tests out the libusb functions.
//=========================================================================

int main (int argc, char *argv)
{
   libusb_device                    **devList = NULL;
   libusb_device                    *devPtr = NULL;
   libusb_device_handle             *devHandle = NULL;
   struct libusb_device_descriptor  devDesc;

   unsigned char              strDesc[256];
   ssize_t                    numUsbDevs = 0;      // pre-initialized scalars
   ssize_t                    idx = 0;
   int                        retVal = 0;

   //========================================================================
   // test out the libusb functions
   //========================================================================

   printf ("*************************\n USB Experiment Program:\n*************************\n");
   retVal = libusb_init (NULL);

   //========================================================================
   // Get the list of USB devices visible to the system.
   //========================================================================

   numUsbDevs = libusb_get_device_list (NULL, &devList);

   //========================================================================
   // Loop through the list, looking for the device with the required values
   // for Manufacturer ("RockwellCollins") and Product ("TACDIS").
   //========================================================================

   while (idx < numUsbDevs)
   {
      printf ("\n[%d]\n", idx+1);

      //=====================================================================
      // Get next device pointer out of the list, use it to open the device.
      //=====================================================================

      devPtr = devList[idx];

      retVal = libusb_open (devPtr, &devHandle);
      if (retVal != LIBUSB_SUCCESS)
         break;

      //=====================================================================
      // Get the device descriptor for this device.
      //=====================================================================

      retVal = libusb_get_device_descriptor (devPtr, &devDesc);
      if (retVal != LIBUSB_SUCCESS)
         break;

      //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   iManufacturer = %d\n", devDesc.iManufacturer);
      if (devDesc.iManufacturer > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.iManufacturer, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }

      //========================================================================
      // Get string associated with iProduct index.
      //========================================================================

      printf ("   iProduct = %d\n", devDesc.iProduct);
      if (devDesc.iProduct > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.iProduct, strDesc, 256);


         printf ("   string = %s\n", strDesc);
      }

      //==================================================================
      // Get string associated with iSerialNumber index.
      //==================================================================

      printf ("   iSerialNumber = %d\n", devDesc.iSerialNumber);
      if (devDesc.iSerialNumber > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.iSerialNumber, strDesc, 256);


         printf ("   string = %s\n", strDesc);
      }
	   
	  //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bDescriptorType = %d\n", devDesc.bDescriptorType);
      if (devDesc.bDescriptorType > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bDescriptorType, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }
	  
	  //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bDeviceClass = %d\n", devDesc.bDeviceClass);
      if (devDesc.bDeviceClass > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bDeviceClass, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }
	   
	   //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bDeviceProtocol = %d\n", devDesc.bDeviceProtocol);
      if (devDesc.bDeviceProtocol > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bDeviceProtocol, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }

	    //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bDeviceSubClass = %d\n", devDesc.bDeviceSubClass);
      if (devDesc.bDeviceSubClass > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bDeviceSubClass, strDesc, 256);
         

         printf ("   string = %s\n",  strDesc);
      }
	   
	   //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   idVendor = %d\n", devDesc.idVendor);
      if (devDesc.idVendor > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.idVendor, strDesc, 256);
        

         printf ("   string = %s\n",  strDesc);
      }
	   
	  //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   idProduct = %d\n", devDesc.idProduct);
      if (devDesc.idProduct > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.idProduct, strDesc, 256);
         

         printf ("   string = %s\n",  strDesc);
      }
	   
	   
	   
	    //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bcdDevice = %d\n", devDesc.bcdDevice);
      if (devDesc.bcdDevice > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bcdDevice, strDesc, 256);
         

         printf ("   string = %s\n",  strDesc);
      }
	   
	     //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bcdUSB = %d\n", devDesc.bcdUSB);
      if (devDesc.bcdUSB > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bcdUSB, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }
	   
	      //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bNumConfigurations = %d\n", devDesc.bNumConfigurations);
      if (devDesc.bNumConfigurations > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bNumConfigurations, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }
	   
	      //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bMaxPacketSize = %d\n", devDesc.bMaxPacketSize0);
      if (devDesc.bMaxPacketSize0 > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bMaxPacketSize0, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }
	   
	      //=====================================================================
      // Get the string associated with iManufacturer index.
      //=====================================================================

      printf ("   bLength = %d\n", devDesc.bLength);
      if (devDesc.bLength > 0)
      {
         retVal = libusb_get_string_descriptor_ascii
                  (devHandle, devDesc.bLength, strDesc, 256);


         printf ("   string = %s\n",  strDesc);
      }
	   
      //========================================================================
      // Close and try next one.
      //========================================================================

      libusb_close (devHandle);
      devHandle = NULL;
      idx++;
   }  // end of while loop

   if (devHandle != NULL)
   {
      //========================================================================
      // Close device if left open due to break out of loop on error.
      //========================================================================

      libusb_close (devHandle);
   }   

   libusb_exit (NULL);

   printf ("\n*************************\n        Done\n*************************\n");
   return 0;
}

//==========================================
// EOF
//==========================================

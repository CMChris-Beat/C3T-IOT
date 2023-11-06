#include <iostream>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_task_wdt.h"

void sendTask(void *pvParam) {
    esp_task_wdt_add(nullptr);
    QueueHandle_t QHandle;
    QHandle = (QueueHandle_t) pvParam;
    BaseType_t xStatus;
    int i = 0;
    while(true) {
        xStatus = xQueueSend(QHandle, &i, 0);
        if(xStatus != pdPASS) printf("Send Fail!\n");
        else printf("Send Done!\n");
        if(i++ == 8) i = 0;
        esp_task_wdt_reset();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void recTask(void *pvParam) {
    esp_task_wdt_add(nullptr);
    QueueHandle_t QHandle;
    QHandle = (QueueHandle_t) pvParam;
    BaseType_t xStatus;
    int j = 0;
    while(true) {
        xStatus = xQueueReceive(QHandle, &j, 0);
        if(xStatus != pdPASS) printf("Receive Fail!\n");
        else printf("Receive Done! j = %d\n", j);
        esp_task_wdt_reset();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

extern "C" void app_main() {
    TaskHandle_t pxTaskSend, pxTaskRec;
    QueueHandle_t QHandle;
    QHandle = xQueueCreate(5, sizeof(int));
    if(QHandle != nullptr) {
        printf("Create queue successfully!\n");
        xTaskCreate(sendTask, "sendTask", 1024 * 5, (void *)QHandle, 1, nullptr);
        xTaskCreate(recTask, "recTask", 1024 * 5, (void *)QHandle, 1, nullptr);
    }else {
        printf("Can not create queue!\n");
    }
}

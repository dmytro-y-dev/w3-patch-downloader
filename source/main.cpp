#include <curl/curl.h>

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <process.h>

void ShowHelp()
{
    const char helpString[] =
        "W3 Patch Downloader\n"
        "-------------------\n"
        "Application to download and install patches from the Web.\n"
        "\n"
        "\n"
        "How to use it\n"
        "-------------\n"
        "w3-patch-downloader just-download <http-address> <output-file-path>\n"
        "w3-patch-downloader download-and-unzip <http-address> [output-directory]\n"
        "\n"
        "Example: w3-patch-downloader just-download http://site.hi/my-file.txt my-file.txt\n"
        "\n"
        "Available actions:\n"
        " - just-download: download file from \"http-address\" and put it to \n"
        "                  \"output-directory\"\n"
        "\n"
        " - download-and-unzip: download .zip archive from \"http-address\" \n"
        "                       and unzip it to \"output-directory\"\n"
        "\n"
        "\n"
        "Developed by metamaker, built on %s %s\n";

    printf(helpString, __DATE__, __TIME__);
}

void ShowError(const char *format, ...)
{
    printf("Error: ");

    va_list arglist;
    va_start(arglist, format);
    vprintf(format, arglist);
    va_end(arglist);

    printf("\n\n");

    ShowHelp();
}

size_t WriteDataToDiskFromCURL(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}

int JustDownload(const char *urlToFile, const char *outputPath)
{
    CURL *curl = curl_easy_init();

    if (curl) {
        FILE *outputFilePointer = fopen(outputPath, "wb");

        if (!outputFilePointer) {
            ShowError("%s%s%s", "Unable to open file ", outputPath, " for writing.");

            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, urlToFile);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteDataToDiskFromCURL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputFilePointer);

        CURLcode curlOperationResult = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        fclose(outputFilePointer);

        if (curlOperationResult != CURLE_OK) {
            return 2;
        }
    }

    return 0;
}

int DownloadAndUnzip(const char *urlToFile, const char *outputDirectory)
{
    const char *temporaryFileName = "W3Patch.tmp.zip";

    int downloadResult = JustDownload(urlToFile, temporaryFileName);
    if (downloadResult != 0) {
        return downloadResult;
    }

    char sevenZipCommand[2048];
    sprintf(sevenZipCommand, "7z x W3Patch.tmp.zip -o%s", outputDirectory);
    system(sevenZipCommand);

    remove(temporaryFileName);

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        ShowHelp();

        return 1;
    }

    if (!strcmp(argv[1], "just-download")) {
        if (argc > 4 || argc < 3) {
            ShowError("%s%d%s", "There must be 3 or 4 arguments for action \"just-download\", ", argc, " is provided.");

            return 1;
        }

        const char *urlToFile = argv[2];
        const char *outputPath = 0;

        if (argc == 4) {
            outputPath = argv[3];
        }

        return JustDownload(urlToFile, outputPath);
    }

    if (!strcmp(argv[1], "download-and-unzip")) {
        if (argc > 4 || argc < 3) {
            ShowError("%s%d%s", "There must be 3 or 4 arguments for action \"download-and-unzip\", ", argc, " is provided.");

            return 1;
        }

        const char *urlToFile = argv[2];
        const char *outputDirectory = 0;

        if (argc == 4) {
            outputDirectory = argv[3];
        }

        return DownloadAndUnzip(urlToFile, outputDirectory);
    }

    ShowError("%s%s%s", "Unknown command \"", argv[1] , "\".");
    
    return 0;
}

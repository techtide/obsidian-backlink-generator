#ifndef NOTE_H
#define NOTE_H

#include "core.h"

namespace hornbeam
{

    /*
     * Data structure for storing notes/text-files in the Obsidian vault,
     * and representing them with their file-wide word/sentence embeddings.
     *
     * To enable support for different word embedding models, each Note object
     * must implement its own computeEmbedding function, connecting to the
     * relevant static model.
     */
    class Note
    {
    public:
        Note(const std::string &filePath, const arma::mat &embedding) : filePath_(filePath), embedding_(embedding) {}

        std::string getFilePath() const { return filePath_; }
        arma::mat getEmbedding() const { return embedding_; }
        int getGroupId() const;

    private:
        std::string filePath_;
        arma::mat embedding_;
        int groupId_;
    };
} // namespace hornbeam

#endif // NOTE_H
